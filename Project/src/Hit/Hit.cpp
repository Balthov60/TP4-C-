/*************************************************************************
                           Hit  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Hit> (fichier Hit.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Hit.h"

using namespace std;
//------------------------------------------------------------- Constantes

const char BASIC_SEPARATOR = ' ';
const char LONG_STRING_SEPARATOR = '"';

const char * const RESOURCE_EXTENSION_LIST[] = {"jpg", "jpeg", "bmp", "tiff", "png", "gif", "css", "js", "ico"};

//----------------------------------------------------------------- PUBLIC

string Hit::GetReferer() const
{
    if (referer.find(SERVER_URL) != -1)
    {
        return referer.substr(SERVER_URL.length(), string::npos);
    }
    else
    {
        return referer;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

istream & operator>>(istream & is, Hit & hit)
{
    string temp;

    getline(is, hit.ip, BASIC_SEPARATOR);
    getline(is, hit.logname, BASIC_SEPARATOR);
    getline(is, hit.authenticatedUser, BASIC_SEPARATOR);

    is >> hit.datetime;
    is >> hit.request;

    getline(is, temp, BASIC_SEPARATOR);
    hit.statusCode = (unsigned int) stoi(temp, nullptr, 10);

    getline(is, temp, BASIC_SEPARATOR);
    hit.setDataQty(temp);

    is.seekg(1, ios_base::cur);
    getline(is, temp, LONG_STRING_SEPARATOR);
    hit.setRefererInfos(temp);

    is.seekg(2, ios_base::cur);
    getline(is, hit.browserInfo, LONG_STRING_SEPARATOR);

    hit.relatedToResourceFile = hit.checkIfHitIsRelatedToAResourceFile(hit.request.getUrl());

    is.seekg(1, ios_base::cur);
    if (is.get() != -1)
        is.seekg(-1, ios_base::cur);

    return is;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Hit::setDataQty(string &temp)
{
    if (temp.c_str()[0] == '-')         //sometimes, field data quantity has '-' char
    {                                   //thus it's necessary to test it manually to avoid stoi errors
        dataQty = 0;
    }
    else
    {
        dataQty = (unsigned int) stoi(temp, nullptr, 10);
    }
}

void Hit::setRefererInfos(string &temp)
{
    unsigned long argsGetpos = temp.find(';');
    if (argsGetpos == string::npos)
        argsGetpos = temp.find_first_of('?');

    if (argsGetpos != string::npos)
    {
        referer = temp.substr(0, argsGetpos);
        refererGetArgs = temp.substr(argsGetpos + 1);
    }
    else
    {
        referer = temp;
    }

    if (referer.back() == '/')
        referer.erase(referer.end() - 1, referer.end());
}

bool Hit::checkIfHitIsRelatedToAResourceFile(const string &filePath)
{
    unsigned long dotPosition = filePath.find_last_of('.');

    if (dotPosition != -1)
    {
       string extension = filePath.substr(dotPosition + 1);
       for (auto &i : RESOURCE_EXTENSION_LIST)
       {
           if (extension == i)
               return true;
       }
    }

    return false;
}
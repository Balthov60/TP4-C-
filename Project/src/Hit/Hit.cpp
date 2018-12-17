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

const unsigned int EXTENSION_NUMBER = 9;
const char * const RESOURCE_EXTENSION_LIST[] = {"jpg", "jpeg", "bmp", "tiff", "png", "gif", "css", "js", "ico"};

//----------------------------------------------------------------- PUBLIC

string Hit::getReferer() const
//Algorithme :
//
{
    if (referer.find(SERVER_URL) != -1) {
        return referer.substr(SERVER_URL.length(), string::npos);
    } else {
        return referer;
    }
}

//------------------------------------------------- Surcharge d'opérateurs
istream & operator>>(istream & is, Hit & hit)
{
    string temp;
    int argsGETpos;

    getline(is, hit.ip, BASIC_SEPARATOR);
    getline(is, hit.logname, BASIC_SEPARATOR);
    getline(is, hit.authenticatedUser, BASIC_SEPARATOR);

    //Dealing with date and time
    is >> hit.datetime;
    //Dealing with request info
    is >> hit.request;

    getline(is, temp, BASIC_SEPARATOR);
    hit.statusCode = (unsigned int) stoi(temp, nullptr, 10);

    //Dealing with data quantity
    getline(is, temp, BASIC_SEPARATOR);
    if (temp.c_str()[0] == '-')         //sometimes, field data quantity has '-' char
    {                                   //thus it's necessary to test it manually to avoid stoi errors
        hit.dataQty = 0;
    } else {
        hit.dataQty = (unsigned int) stoi(temp, nullptr, 10);
    }

    //Dealing with referer
    is.seekg(1, ios_base::cur);
    getline(is, temp, LONG_STRING_SEPARATOR);
    argsGETpos = temp.find('?');
    if (argsGETpos != -1 ){
        hit.referer = temp.substr(0,argsGETpos);
        hit.refererGetArgs = temp.substr(argsGETpos+1,string::npos);
    } else {
        hit.referer = temp;
    }

    is.seekg(2, ios_base::cur);
    getline(is, hit.browserInfo, LONG_STRING_SEPARATOR);

    hit.relatedToResourceFile = hit.checkRelatedToResourceFile(hit.request.getUrl());

    //getline(is, temp);  // Remove end of file indicator (use of this line generates an error at the end of anonyme.log)
    //TODO : find a better fix to EOF problem.
    is.seekg(1, ios_base::cur);
    if (is.get() != -1)
        is.seekg(-1,ios_base::cur);


    return is;
} // Fin operator >>

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées

bool Hit::checkRelatedToResourceFile(const string &filePath)
//Algorithme:
//
{
    bool related = false;
    int dotPosition = filePath.find('.');
    if (dotPosition != -1)
    {
        unsigned int i;
        string extension = filePath.substr(dotPosition+1,4);
       for(i=0;i < EXTENSION_NUMBER && extension.compare(RESOURCE_EXTENSION_LIST[i])!=0; i++);
       if (i < EXTENSION_NUMBER) related = true;
    }

    return related;
}
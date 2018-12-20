/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//------ Réalisation de la classe <Request> (fichier Request.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel

#include "Request.h"

using namespace std;

//------------------------------------------------------------- Constantes

const char BASIC_SEPARATOR          = ' ';
const char LONG_STRING_SEPARATOR    = '"';

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

istream & operator>>(istream & is, Request & request)
{
    string temp, urlTemp;
    is.seekg(2, ios_base::cur);

    getline(is, request.type, BASIC_SEPARATOR);

    getline(is, temp, LONG_STRING_SEPARATOR);
    unsigned long lastSpacePos = temp.rfind(' ');
    request.protocol = temp.substr(lastSpacePos + 1);

    temp = temp.substr(0, lastSpacePos);
    request.setUrlInfos(temp);

    is.seekg(1, ios_base::cur);

    return is;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Request::setUrlInfos(string &temp) // TODO: Create new Object for URL to remove code redundancy with Hit Class
{
    unsigned long argsGetpos = temp.find('?');
    if (argsGetpos == string::npos)
        argsGetpos = temp.find(';');

    if (argsGetpos != string::npos)
    {
        url = temp.substr(0, argsGetpos);
        urlGetArgs = temp.substr(argsGetpos + 1);
    }
    else
    {
        url = temp;
    }

    if (url.back() == '/' && url.size() > 1)
        url.erase(url.end() - 1, url.end());
}
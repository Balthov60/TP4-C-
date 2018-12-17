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
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Request.h"

using namespace std;
//------------------------------------------------------------- Constantes
const char BASIC_SEPARATOR = ' ';
const char LONG_STRING_SEPARATOR = '"';
//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

istream & operator>>(istream & is, Request & request)
{
    string temp;
    string urlAndProtocolString;
    int argsGETpos;
    int lastSpacePos;


    is.seekg(2, ios_base::cur);


    getline(is, request.type, BASIC_SEPARATOR);

    //dealing with url and protocol
    getline(is,urlAndProtocolString, LONG_STRING_SEPARATOR);
    lastSpacePos = urlAndProtocolString.rfind(" ");
    request.protocol = urlAndProtocolString.substr(lastSpacePos+1,string::npos);
    temp = urlAndProtocolString.substr(0,lastSpacePos);


    argsGETpos = temp.find('?');
    if (argsGETpos != -1 ){
        request.url = temp.substr(0,argsGETpos);
        request.url = temp.substr(argsGETpos+1,string::npos);
    } else {
        request.url = temp;
    }


    is.seekg(1, ios_base::cur);

    return is;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


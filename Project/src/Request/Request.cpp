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
const char BASIC_SEPARATOR = ' ';
const char LONG_STRING_SEPARATOR = '"';
//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

istream & operator>>(istream & is, Request & request)
{
    is.seekg(2, ios_base::cur);

    getline(is, request.type, BASIC_SEPARATOR);
    getline(is, request.url, BASIC_SEPARATOR);
    getline(is, request.protocol, LONG_STRING_SEPARATOR);

    is.seekg(1, ios_base::cur);

    return is;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


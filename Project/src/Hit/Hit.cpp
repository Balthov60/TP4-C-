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

//----------------------------------------------------------------- PUBLIC

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
    // hit.statusCode = (unsigned int) stoi(temp, nullptr, 10);

    getline(is, temp, BASIC_SEPARATOR);
    // hit.dataQty = (unsigned int) stoi(temp, nullptr, 10);

    is.seekg(1, ios_base::cur);
    getline(is, hit.referer, LONG_STRING_SEPARATOR);

    is.seekg(2, ios_base::cur);
    getline(is, hit.browserInfo, LONG_STRING_SEPARATOR);

    if (!is.eof())
        is.seekg(1, ios_base::cur);

    return is;
}
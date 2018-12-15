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
    hit.statusCode = (unsigned int) stoi(temp, nullptr, 10);

    getline(is, temp, BASIC_SEPARATOR);
    if (temp.c_str()[0] == '-')         //sometimes, field data quantity has '-' char
    {                                   //thus it's necessary to test it manually to avoid stoi errors
        hit.dataQty = 0;
    } else {
        hit.dataQty = (unsigned int) stoi(temp, nullptr, 10);
    }

    is.seekg(1, ios_base::cur);
    getline(is, hit.referer, LONG_STRING_SEPARATOR);

    is.seekg(2, ios_base::cur);
    getline(is, hit.browserInfo, LONG_STRING_SEPARATOR);

    //getline(is, temp);  // Remove end of file indicator (use of this line generates an error at the end of anonyme.log)
    //TODO : find a better fix to EOF problem.
    is.seekg(1, ios_base::cur);
    if (is.get() != -1)
        is.seekg(-1,ios_base::cur);


    return is;
}
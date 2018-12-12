/*************************************************************************
                           Datetime  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Datetime> (fichier Datetime.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Datetime.h"

using namespace std;
//------------------------------------------------------------- Constantes

const char DATE_SEPARATOR = '/';
const char TIME_SEPARATOR = ':';
const char BASIC_SEPARATOR = ' ';
const char END_INDICATOR = ']';

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

istream & operator>>(istream & is, Datetime & datetime)
{
    string temp;

    is.seekg(1, ios_base::cur);                 // Escape First Start Indicator

    getline(is, temp, DATE_SEPARATOR);
    cout << temp << endl;
    datetime.day = (unsigned short) stoul(temp, nullptr,10);

    getline(is, temp, DATE_SEPARATOR);
    sprintf(datetime.month, "%.4s", temp.c_str());

    getline(is, temp, TIME_SEPARATOR);
    datetime.year = (unsigned short) stoul(temp, nullptr,10);

    getline(is,temp, TIME_SEPARATOR);
    datetime.hour = (unsigned short) stoul(temp, nullptr,10);

    getline(is, temp, TIME_SEPARATOR);
    datetime.minutes = (unsigned short) stoul(temp, nullptr, 10);

    getline(is, temp ,BASIC_SEPARATOR);
    datetime.seconds = (unsigned short) stoul(temp, nullptr, 10);

    getline(is, datetime.utc, END_INDICATOR);

    return is;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


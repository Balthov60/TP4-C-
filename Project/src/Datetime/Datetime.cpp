/*************************************************************************
                           Datetime  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Datetime> (fichier Datetime.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Datetime.h"

using namespace std;
//------------------------------------------------------------- Constantes
const char SEP_SLASH='/';
const char SEP_COL = ':';
const char SEP_SPACE = ' ';
const char SEP_BRACKR = ']';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

istream & operator >> (istream & is, Datetime & datetime)
//Algorithme :
//
{
    unsigned int i;
    string temporary;

    is.seekg(1, ios_base::cur);
    getline(is, temporary, SEP_SLASH);
    datetime.day = stoul(temporary, nullptr,10);

    getline(is, temporary, SEP_SLASH);
    sprintf(datetime.month, "%.4s", temporary.c_str());

    getline(is, temporary, SEP_COL);
    datetime.year = stoul(temporary, nullptr,10);

    getline(is,temporary, SEP_COL);
    datetime.hour = stoul(temporary, nullptr,10);

    getline(is, temporary, SEP_COL);
    datetime.minutes = stoul(temporary, nullptr, 10);

    getline(is,temporary,SEP_SPACE);
    datetime.secondes = stoul(temporary, nullptr, 10);

    getline(is, datetime.utc,SEP_BRACKR);

    /*cout << datetime.day << endl;
    cout << datetime.month << endl;
    cout << datetime.year  << endl;
    cout << datetime.hour << endl;
    cout << datetime.minutes << endl;
    cout << datetime.secondes << endl;
    cout << datetime.utc << endl;*/

    return is;
}

//-------------------------------------------- Constructeurs - destructeur
Datetime::Datetime ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Datetime>" << endl;
#endif
} //----- Fin de Datetime


Datetime::~Datetime ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Datetime>" << endl;
#endif
} //----- Fin de ~Datetime


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


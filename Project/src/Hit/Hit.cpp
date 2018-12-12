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

const char SEP_SPACE = ' ';
const char SEP_QUOTE = '"';

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & is, Hit & hit){
    int monInt;

    string strStatusCode,strDataQty;

    getline(is, hit.ip, SEP_SPACE);
    getline(is, hit.logname, SEP_SPACE);
    getline(is, hit.authenticatedUser, SEP_SPACE);


    is >> hit.datetime;
    is >> hit.request;
    is.seekg(1,ios_base::cur);

    getline(is, strStatusCode,SEP_SPACE);
    getline(is, strDataQty, SEP_SPACE);
    is.seekg(1,ios_base::cur);
    getline(is, hit.referer, SEP_QUOTE);

    is.seekg(2,ios_base::cur);
    getline(is, hit.browserInfo, SEP_QUOTE);

    hit.statusCode = stoul(strStatusCode,nullptr,10);
    hit.dataQty = stoul(strDataQty,nullptr,10);

    if (!is.eof())
        is.seekg(1,ios_base::cur);

    return is;
}

//-------------------------------------------- Constructeurs - destructeur

Hit::Hit ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Hit>" << endl;
#endif
} //----- Fin de Hit


Hit::~Hit ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Hit>" << endl;
#endif
} //----- Fin de ~Hit


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


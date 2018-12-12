/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Request.h"

using namespace std;
//------------------------------------------------------------- Constantes
const char SEP_SPACE = ' ';
const char SEP_QUOTE = '"';
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & is, Request & request)
//Algorithme :
//
{
    is.seekg(2,ios_base::cur);
    getline(is,request.type,SEP_SPACE);
    getline(is,request.url,SEP_SPACE);
    getline(is,request.protocol,SEP_QUOTE);

    /*cout << request.type << endl;
    cout << request.url << endl;
    cout << request.protocol << endl;*/

}



//-------------------------------------------- Constructeurs - destructeur

Request::Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request


Request::~Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


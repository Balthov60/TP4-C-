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
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Datetime.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Datetime::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Datetime & Datetime::operator = ( const Datetime & unDatetime )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Datetime::Datetime ( const Datetime & unDatetime )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Datetime>" << endl;
#endif
} //----- Fin de Datetime (constructeur de copie)


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


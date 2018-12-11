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
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Hit.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Hit::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Hit & Hit::operator = ( const Hit & unHit )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Hit::Hit ( const Hit & unHit )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Hit>" << endl;
#endif
} //----- Fin de Hit (constructeur de copie)


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


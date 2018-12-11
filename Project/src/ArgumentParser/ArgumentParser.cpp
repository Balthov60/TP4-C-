/*************************************************************************
                           ArgumentParser  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ArgumentParser> (fichier ArgumentParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ArgumentParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ArgumentParser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ArgumentParser & ArgumentParser::operator = ( const ArgumentParser & unArgumentParser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ArgumentParser::ArgumentParser ( const ArgumentParser & unArgumentParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ArgumentParser>" << endl;
#endif
} //----- Fin de ArgumentParser (constructeur de copie)


ArgumentParser::ArgumentParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ArgumentParser>" << endl;
#endif
} //----- Fin de ArgumentParser


ArgumentParser::~ArgumentParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ArgumentParser>" << endl;
#endif
} //----- Fin de ~ArgumentParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


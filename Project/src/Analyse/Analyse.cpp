/*************************************************************************
                           Analyse  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Analyse.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Analyse::Run()
//Algorithme :
//
{
    LogReader * logReader = LogReader::GetInstance();
    while(analyseNextLog(*logReader));
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse ( ):hour(-1),excludeResourcesFile(false),generateGraph(false)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif
} //----- Fin de Analyse


Analyse::~Analyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
bool Analyse::analyseNextLog(LogReader & logReader)
//Algorithme :
//
{
    Hit * hitPtr;
    hitPtr = logReader.readNext();

    if (hitPtr)
    {

        return true;
    } else {
        return false;
    }
}

void Analyse::generateOrderedNodeCounterMap()
//Algorithme :
//
{

}

void Analyse::generateGraphMapper()
//Algorithme :
//
{

}

void Analyse::displayResult()
//Algorithme :
//
{

}

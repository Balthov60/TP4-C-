/*************************************************************************
                           GraphVizWriter  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GraphVizWriter> (fichier GraphVizWriter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "GraphVizWriter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GraphVizWriter::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
GraphVizWriter & GraphVizWriter::operator = ( const GraphVizWriter & unGraphVizWriter )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphVizWriter::GraphVizWriter ( const GraphVizWriter & unGraphVizWriter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphVizWriter>" << endl;
#endif
} //----- Fin de GraphVizWriter (constructeur de copie)


GraphVizWriter::GraphVizWriter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphVizWriter>" << endl;
#endif
} //----- Fin de GraphVizWriter


GraphVizWriter::~GraphVizWriter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphVizWriter>" << endl;
#endif
} //----- Fin de ~GraphVizWriter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


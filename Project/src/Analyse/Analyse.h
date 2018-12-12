/*************************************************************************
                           Analyse  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( Analyse_H )
#define Analyse_H

//--------------------------------------------------- Interfaces utilisées

#include "../GraphVizWriter/GraphVizWriter.h"
#include "../LogReader/LogReader.h"
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------

class Analyse
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string file;
    string graph;
    int hour;
    bool excludeResourcesFile;
    bool generateGraph;

    //unordered_map<pair<string,string>,unsigned int> graphMapper;
    unordered_map<string,unsigned int> nodeCounterMap;
    multimap<unsigned int, string *> orderedNodeCounterMap;
};

//-------------------------------- Autres définitions dépendantes de <Analyse>

#endif // Analyse_H


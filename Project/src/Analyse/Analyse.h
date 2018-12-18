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

#include <utility>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef unordered_map<string, unsigned int> NodeCounter;

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
    void Run();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SetGraph(const string & graphPath)
    {
        this->generateGraph = true;
        this->graphPath = graphPath;
    }

    void SetHour(int hour)
    {
        this->hour = hour;
    }

    void SetExcludeResourcesFile(bool excludeResourcesFile)
    {
        this->excludeResourcesFile = excludeResourcesFile;
    }

    void SetLogReader(LogReader * logReader)
    {
        this->logReader = logReader;
    }



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Analyse ();
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

    bool analyseNextLog();
    // Mode d'emploi :
    //
    // Contrat :
    //
    const string * updateNodeCounterMapWithUrl(const string &url);
    const string * getRefererStringInNodeCounterMap(const string &referer);
    void updateGraphMapper(const string * referer, const string * url);

    void generateOrderedNodeCounterMap();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void generateGraphMapper();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void displayResult();
    // Mode d'emploi :
    //
    // Contrat :
    //


//----------------------------------------------------- Attributs protégés
    string graphPath;
    int hour;
    bool excludeResourcesFile;
    bool generateGraph;

    LogReader * logReader;

    GraphMapper graphMapper;
    NodeCounter nodeCounter;
    multimap<unsigned int, const string *> orderedNodeCounterMap;
};

//-------------------------------- Autres définitions dépendantes de <Analyse>

#endif // Analyse_H


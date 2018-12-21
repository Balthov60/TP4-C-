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
typedef multimap<unsigned int, const string *> OrderedNodeCounter;

//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
// Classe principale de l'application, permet de créer les structures de données
// utilisé pour créé un top 10 et pour créer le graph.
//
//------------------------------------------------------------------------

class Analyse
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Run();
    // Mode d'emploi :
    // Run Analysis on log, generate graph if asked and display top 10.
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

//-------------------------------------------- Constructeurs - destructeur

    Analyse ():hour(-1), excludeResourcesFile(false), generateGraph(false) {};
    // Mode d'emploi :
    // default constructor
    //
    // Contrat :
    //

    virtual ~Analyse () = default;
    // Mode d'emploi :
    // default destructor
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Méthodes protégées

    bool analyseNextHit();
    // Mode d'emploi :
    // Get next Hit and add it to NodeCounter if it match analysis parameters.
    //
    // Contrat :
    //

    const string * updateNodeCounterMapWithUrl(const string &url);
    // Mode d'emploi :
    // Add an entry or increment NodeCounter
    //
    // Contrat :
    //
    const string * getRefererStringInNodeCounterMap(const string &referer);
    // Mode d'emploi :
    // Get Referer String pointer from counter map or insert a new one if it don't exist.
    //
    // Contrat :
    //

    void updateGraphMapper(const string * referer, const string * url);
    // Mode d'emploi :
    // Add an entry or increment GraphMapper
    //
    // Contrat :
    //

    void generateOrderedNodeCounterMap();
    // Mode d'emploi :
    // Generate Ordered Node Counter by inverting nodeCounter Map.
    //
    // Contrat :
    //

    void displayResult();
    // Mode d'emploi :
    // Display a top ten from orderedNodeCounterMap.
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
    OrderedNodeCounter orderedNodeCounter;
};

//-------------------------------- Autres définitions dépendantes de <Analyse>

#endif // Analyse_H


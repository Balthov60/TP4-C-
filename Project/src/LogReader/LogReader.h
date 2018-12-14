/*************************************************************************
                           LogReader  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <LogReader> (fichier LogReader.h) ----------
#if ! defined ( LogReader_H )
#define LogReader_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>

#include "../Hit/Hit.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogReader>
//
// La classe LogReader permet de charger et de lire le contenu d'un fichier
// de log en créant des objets Hit pour chaque entrée.
//
//------------------------------------------------------------------------

class LogReader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    Hit * ReadNext();
    // Mode d'emploi :
    // Lit la prochaine ligne de log.
    // Renvoi nullptr si le fichier de log est terminée.
    // Sinon renvoi un objet Hit correspondant au log lu.
    //
    // Contrat:
    //

    bool TrackNewFile(const string & path);
    // Mode d'emploi :
    // Ferme l'ancien flux et essaye d'en ouvrir un nouveau sur le fichier pointé par "path"
    // Renvoi true si le fichier est correctement ouvert sinon renvoi false.
    //
    // Contrat:
    //

    void CloseFileStream();
    // Mode d'emploi :
    // Ferme le flux si il est ouvert.
    //
    // Contrat:
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    explicit LogReader(const string & path);
    // Mode d'emploi :
    // Crée un object LogReader et lui associe un fichier de log.
    //
    // Contrat :
    //

    virtual ~LogReader();
    // Mode d'emploi :
    // Ferme le flux du fichier de log.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ifstream stream;

};

//-------------------------- Autres définitions dépendantes de <LogReader>

#endif // LogReader_H


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
    // Read Next Log from stream.
    // return nullptr if stream is ended.
    // else return an instance of the Hit created.
    //
    // Contrat:
    //

    bool TrackNewFile(const string & path);
    // Mode d'emploi :
    // Close the old stream and try to open a new one at path
    // Return true if file opened successfully else return false.
    //
    // Contrat:
    //

    void CloseFileStream();
    // Mode d'emploi :
    // Close stream if opened.
    //
    // Contrat:
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    explicit LogReader(const string & path);
    // Mode d'emploi :
    // Instantiate LogReader and open stream at path.
    //
    // Contrat :
    //

    virtual ~LogReader();
    // Mode d'emploi :
    // close istream.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés

    ifstream stream;

};

//-------------------------- Autres définitions dépendantes de <LogReader>

#endif // LogReader_H


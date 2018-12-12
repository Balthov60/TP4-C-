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

#include "../Hit/Hit.h"
#include <fstream>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogReader>
//
//
//------------------------------------------------------------------------

class LogReader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    LogReader * GetInstance();
    // Mode d'emploi :
    //
    // Contrat:
    //

    Hit * readnext();
    // Mode d'emploi :
    //
    // Contrat:
    //

    bool TrackNewFile(const string & path);
    // Mode d'emploi :
    //
    // Contrat:
    //

    void CloseFileStream();
    // Mode d'emploi :
    //
    // Contrat:
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

private:
    LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

public:
    virtual ~LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ifstream stream;
    LogReader * instance;

};

//-------------------------- Autres définitions dépendantes de <LogReader>

#endif // LogReader_H


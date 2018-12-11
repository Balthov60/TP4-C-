/*************************************************************************
                           LogReader  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogReader> (fichier LogReader.h) ----------------
#if ! defined ( LogReader_H )
#define LogReader_H

//--------------------------------------------------- Interfaces utilisées

#include "../Hit/Hit.h"

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    LogReader & operator = ( const LogReader & unLogReader );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogReader ( const LogReader & unLogReader );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogReader>

#endif // LogReader_H


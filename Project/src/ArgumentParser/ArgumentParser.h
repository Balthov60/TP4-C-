/*************************************************************************
                           ArgumentParser  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

// Interface de la classe <ArgumentParser> (fichier ArgumentParser.h)
#if ! defined ( ArgumentParser_H )
#define ArgumentParser_H

//--------------------------------------------------- Interfaces utilisées

#include <regex>

#include "../LogReader/LogReader.h"
#include "../Analyse/Analyse.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum PARSE_RESULTS {
    GOOD,
    FILE_NO_OVERRIDE,
    FILE_NOT_FOUND,
    PARSING_ERROR,
    INVALID_VALUE,
};

//------------------------------------------------------------------------
// Rôle de la classe <ArgumentParser>
//
// Parse la commande en entrée et configure l'instance d'Analyse associée
//
//------------------------------------------------------------------------

class ArgumentParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    static PARSE_RESULTS Parse(string &args, Analyse &analyse);
    // Mode d'emploi :
    // Check if args are well formatted and setup analyse according to them.
    //
    // args     : string    command args.
    // analyse  : Analyse   analyse object to be configured..
    // return   : Boolean   true if args are well formatted, else false.
    //

//-------------------------------------------- Constructeurs - destructeur

    ArgumentParser() = delete;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


    static bool testTimeArgs(string &args, Analyse &analyse);
    // Mode d'emploi :
    // Check temps args formatting and configure analyse according to it.
    //
    // return : true if args is well formatted, false sinon.
    //

    static bool testGraphArgs(string &args, Analyse &analyse);
    // Mode d'emploi :
    // Check graph generation args formatting and configure analyse according to it.
    //
    // return : true if args is well formatted, false sinon.
    //

    static bool testLogArgs(string &args, Analyse &analyse);
    // Mode d'emploi :
    // Check log path args formatting and configure analyse according to it.
    //
    // return : true if args is well formatted, false sinon.
    //

    static bool askForFileOverride();
    // Mode d'emploi :
    // Ask user to confirm if he want to override file (with O/N)
    //
    // return : true or false according to user answer.

//----------------------------------------------------- Attributs protégés

    static const regex commandRegex;
    static const regex graphPathArgRegex;
    static const regex timeArgRegex;
    static const regex logPathArgRegex;
};

//--------------------- Autres définitions dépendantes de <ArgumentParser>

#endif // ArgumentParser_H


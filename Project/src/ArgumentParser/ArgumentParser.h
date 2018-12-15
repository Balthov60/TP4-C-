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

//------------------------------------------------------------------------
// Rôle de la classe <ArgumentParser>

// Parse la commande en entrée et crée l'instance d'Analyse associé
//
//------------------------------------------------------------------------

class ArgumentParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    static bool Parse(string &command, Analyse &analyse);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    ArgumentParser() = delete;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


    static bool testTimeArgs(string &command, Analyse &analyse);

    static bool testGraphArgs(string &command, Analyse &analyse);
    static bool askForFileOverride();

    static bool testLogArgs(string &command, Analyse &analyse);

//----------------------------------------------------- Attributs protégés
    static const regex commandRegex;
    static const regex graphPathArgRegex;
    static const regex timeArgRegex;
    static const regex logPathArgRegex;

};

//--------------------- Autres définitions dépendantes de <ArgumentParser>

#endif // ArgumentParser_H


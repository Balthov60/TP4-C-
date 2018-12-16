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
//
// Parse la commande en entrée et configure l'instance d'Analyse associée
//
//------------------------------------------------------------------------

class ArgumentParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    static bool Parse(string &args, Analyse &analyse);
    // Mode d'emploi :
    // Vérifie que les arguments sont bien formatté et configurer l'analyse passé en paramètre.
    //
    // args     : string    contenant les arguments de la command.
    // analyse  : Analyse   l'analyse est configuré selon les arguments rencontré par le parser.
    // return   : true si les arguments sont bien formattés, false sinon.
    //

//-------------------------------------------- Constructeurs - destructeur

    ArgumentParser() = delete;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


    static bool testTimeArgs(string &command, Analyse &analyse);
    // Mode d'emploi :
    // Vérifie l'arguments de temps et configure analyse avec le contenu.
    //
    // return : true si l'argument est bien formatté, false sinon.
    //

    static bool testGraphArgs(string &command, Analyse &analyse);
    // Mode d'emploi :
    // Vérifie l'arguments de génération de graph et configure analyse avec le contenu.
    //
    // return : true si l'argument est bien formatté, false sinon.
    //

    static bool testLogArgs(string &command, Analyse &analyse);
    // Mode d'emploi :
    // Vérifie l'arguments de path des logs et configure analyse avec le contenu.
    //
    // return : true si l'argument est bien formatté, false sinon.
    //

    static bool askForFileOverride();
    // Mode d'emploi :
    // Demande à l'utilisateur si il veut ecraser un fichier.
    //
    // return : true ou false selon la réponse.

//----------------------------------------------------- Attributs protégés

    static const regex commandRegex;
    static const regex graphPathArgRegex;
    static const regex timeArgRegex;
    static const regex logPathArgRegex;
};

//--------------------- Autres définitions dépendantes de <ArgumentParser>

#endif // ArgumentParser_H


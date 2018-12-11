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

    static bool Parse(int argc, char * Argv[], Analyse & Analyse);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    ArgumentParser() = delete;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------- Autres définitions dépendantes de <ArgumentParser>

#endif // ArgumentParser_H


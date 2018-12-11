/*************************************************************************
                           ArgumentParser  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ArgumentParser> (fichier ArgumentParser.h) ----------------
#if ! defined ( ArgumentParser_H )
#define ArgumentParser_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ArgumentParser>
//
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


//------------------------------------------------- Surcharge d'opérateurs
    ArgumentParser & operator = ( const ArgumentParser & unArgumentParser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ArgumentParser ( const ArgumentParser & unArgumentParser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ArgumentParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ArgumentParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ArgumentParser>

#endif // ArgumentParser_H


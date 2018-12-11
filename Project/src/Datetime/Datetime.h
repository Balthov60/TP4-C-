/*************************************************************************
                           Datetime  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Datetime> (fichier Datetime.h) ----------------
#if ! defined ( Datetime_H )
#define Datetime_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Datetime>
//
//
//------------------------------------------------------------------------

class Datetime
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
    Datetime & operator = ( const Datetime & unDatetime );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Datetime ( const Datetime & unDatetime );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Datetime ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Datetime ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Datetime>

#endif // Datetime_H


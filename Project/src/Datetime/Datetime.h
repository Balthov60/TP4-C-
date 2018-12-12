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
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes

const unsigned short int NB_CHAR_MONTH = 3;
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

//------------------------------------------------- Surcharge d'opérateurs

friend istream & operator >> (istream & is, Datetime & datetime);

//-------------------------------------------- Constructeurs - destructeur

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
    unsigned short int day;
    char month[NB_CHAR_MONTH+1];
    unsigned short int year;
    unsigned short int hour;
    unsigned short int minutes;
    unsigned short int secondes;
    string utc;

};

//-------------------------------- Autres définitions dépendantes de <Datetime>

#endif // Datetime_H


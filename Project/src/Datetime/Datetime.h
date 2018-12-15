/*************************************************************************
                           Datetime  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//----- Interface de la classe <Datetime> (fichier Datetime.h) -----------
#if ! defined ( Datetime_H )
#define Datetime_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes

const unsigned short int MONTH_LENGTH = 3;

//------------------------------------------------------------------------
// Rôle de la classe <Datetime>
//
// Permet de lire et de stocker un objet datetime.
//------------------------------------------------------------------------

class Datetime
{
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------------------- Methode publics

    unsigned short GetDay() const {
        return day;
    }

    const char * GetMonth() const {
        return month;
    }

    unsigned short GetYear() const {
        return year;
    }

    unsigned short GetHour() const {
        return hour;
    }

    unsigned short GetMinutes() const {
        return minutes;
    }

    unsigned short GetSecondes() const {
        return seconds;
    }

    const string& GetUtc() const {
        return utc;
    }

//------------------------------------------------- Surcharge d'opérateurs

friend istream & operator>>(istream & is, Datetime & datetime);

//-------------------------------------------- Constructeurs - destructeur

    Datetime() = default;
    // Mode d'emploi :
    // Constructeur vide
    //
    // Contrat :
    //

    virtual ~Datetime() = default;
    // Mode d'emploi :
    // Destructeur vide
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unsigned short int day{};
    char month[MONTH_LENGTH+1]{};
    unsigned short int year{};

    unsigned short int hour{};
    unsigned short int minutes{};
    unsigned short int seconds{};

    string utc;
};

//--------------------------- Autres définitions dépendantes de <Datetime>

#endif // Datetime_H


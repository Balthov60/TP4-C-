/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Request> (fichier Request.h) ----------------
#if ! defined ( Request_H )
#define Request_H


//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
//
//------------------------------------------------------------------------

class Request
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs
    friend istream & operator >> (istream & is, Request & request);

//-------------------------------------------- Constructeurs - destructeur
    Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string type;
    string url;
    string protocol;
};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // Request_H


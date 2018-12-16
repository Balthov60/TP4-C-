/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Request> (fichier Request.h) -----------
#if ! defined ( Request_H )
#define Request_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
// Permet de lire et de stocker un objet Request.
//
//------------------------------------------------------------------------

class Request
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string & getType() const {
        return type;
    }

    const string & getUrl() const {
        return url;
    }

    const string & getProtocol() const {
        return protocol;
    }

//------------------------------------------------- Surcharge d'opérateurs

    friend istream & operator>>(istream & is, Request & request);

//-------------------------------------------- Constructeurs - destructeur
    Request() = default;
    // Mode d'emploi :
    // Constructeur vide
    //
    // Contrat :
    //

    virtual ~Request() = default;
    // Mode d'emploi :
    // Destructeur vide
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string type;
    string url;
    string urlGetArgs;
    string protocol;
};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // Request_H


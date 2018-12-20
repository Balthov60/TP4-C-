/*************************************************************************
                           Hit  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Hit> (fichier Hit.h) ----------------
#if ! defined ( Hit_H )
#define Hit_H

//--------------------------------------------------- Interfaces utilisées
#include "../Datetime/Datetime.h"
#include "../Request/Request.h"
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes

// Change this value according to the server where you record the logs.
const static string SERVER_URL = "http://intranet-if.insa-lyon.fr";

//------------------------------------------------------------------------
// Rôle de la classe <Hit>
//
// Permet de lire et de stocker une ligne de log.
//------------------------------------------------------------------------

class Hit
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string & GetIp() const {
        return ip;
    }

    const string & GetLogname() const {
        return logname;
    }

    const string & GetAuthenticatedUser() const {
        return authenticatedUser;
    }

    const Datetime & GetDatetime() const {
        return datetime;
    }

    const Request & GetRequest() const {
        return request;
    }

    unsigned int GetStatusCode() const {
        return statusCode;
    }

    unsigned int GetDataQty() const {
        return dataQty;
    }

    string GetReferer() const;

    string GetRefererGetArgs() const {
        return refererGetArgs;
    }

    const string & GetBrowserInfo() const {
        return browserInfo;
    }

    bool IsRelatedToResourceFile() const {
     return relatedToResourceFile;
    }

//------------------------------------------------- Surcharge d'opérateurs

    friend istream & operator>>(istream & is, Hit & hit);
    // Mode d'emploi :
    // Fill hit instance with the first hit data found in is.
    //
    // Contrat :
    // is content must be well formatted.
    //

//-------------------------------------------- Constructeurs - destructeur

    Hit() = default;
    // Mode d'emploi :
    // Empty Constructor
    //
    // Contrat :
    //

    virtual ~Hit() = default;
    // Mode d'emploi :
    // Empty Destructor
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void setDataQty(string &temp);
    // Modd d'emploi:
    // Check if temp contain DataQty else set to 0
    //
    // Contrat :
    //

    void setRefererInfos(string &temp);
    // Modd d'emploi:
    // Split URL Args from Referer.
    //
    // Contrat :
    //

    bool checkIfHitIsRelatedToAResourceFile(const string &filePath);
    // Mode d'emploi:
    // Return true if file extension exist in RESOURCE_EXTENSION_LIST
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    string ip;
    string logname;
    string authenticatedUser;

    Datetime datetime;
    Request request;

    unsigned int statusCode;
    unsigned int dataQty;

    string referer;
    string refererGetArgs;

    string browserInfo;
    bool relatedToResourceFile;
};

//-------------------------------- Autres définitions dépendantes de <Hit>

#endif // Hit_H


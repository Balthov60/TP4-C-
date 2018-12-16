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
const string SERVER_URL = "http://intranet-if.insa-lyon.fr";
//------------------------------------------------------------------ Types

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

    const string & getIp() const {
        return ip;
    }

    const string & getLogname() const {
        return logname;
    }

    const string & getAuthenticatedUser() const {
        return authenticatedUser;
    }

    const Datetime & getDatetime() const {
        return datetime;
    }

    const Request & getRequest() const {
        return request;
    }

    unsigned int getStatusCode() const {
        return statusCode;
    }

    unsigned int getDataQty() const {
        return dataQty;
    }

    string getReferer() const;
    //Mode d'empoi :
    //
    // Contrat :
    //

    const string & getBrowserInfo() const {
        return browserInfo;
    }

    bool isRelatedToResourceFile() const {
     return relatedToResourceFile;
    }

//------------------------------------------------- Surcharge d'opérateurs

    friend istream & operator>>(istream & is, Hit & hit);
    // Mode d'emploi :
    // Prend un flux en entrée et remplit l'instance avec les premières informations trouvées.
    //
    // Contrat :
    // Le contenu du flux doit être formatté correctement.
    //

//-------------------------------------------- Constructeurs - destructeur

    Hit() = default;
    // Mode d'emploi :
    // Constructeur vide
    //
    // Contrat :
    //

    virtual ~Hit() = default;
    // Mode d'emploi :
    // Destructeur vide
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool checkRelatedToResourceFile(const string & filePath);
    //Mode d'emploi:
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


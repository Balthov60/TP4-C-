/*************************************************************************
                           GraphVizWriter  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GraphVizWriter> (fichier GraphVizWriter.h) ----------------
#if ! defined ( GraphVizWriter_H )
#define GraphVizWriter_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphVizWriter>
//
//
//------------------------------------------------------------------------

class GraphVizWriter
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
    GraphVizWriter & operator = ( const GraphVizWriter & unGraphVizWriter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GraphVizWriter ( const GraphVizWriter & unGraphVizWriter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphVizWriter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphVizWriter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GraphVizWriter>

#endif // GraphVizWriter_H


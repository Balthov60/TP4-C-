/*************************************************************************
                           LogReader  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <LogReader> (fichier LogReader.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogReader.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
LogReader *LogReader::GetInstance()
// Algorithme :
//
{
    if (!instance)
        instance = new LogReader;

    return instance;
}

Hit * LogReader::readnext()
// Algorithme :
//
{
  Hit * hit;
  if (!stream.eof())
  {
      hit = new Hit;
      stream >> *hit;
  }
  return hit;
}

bool LogReader::TrackNewFile(const string &path)
//Algorithme :
//
{
    stream.open(path,ios_base::in);
    return(stream.good());
}

void LogReader::CloseFileStream()
//Algorithme :
//
{
    stream.close();
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

LogReader::~LogReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogReader>" << endl;
#endif
} //----- Fin de ~LogReader


//------------------------------------------------------------------ PRIVE
//-------------------------------------------- Constructeurs - destructeur
LogReader::LogReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogReader>" << endl;
#endif
} //----- Fin de LogReader



//----------------------------------------------------- Méthodes protégées


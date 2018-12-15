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
#include <exception>

//------------------------------------------------------ Include personnel
#include "LogReader.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Hit * LogReader::ReadNext()
{
    if (stream.is_open() && !stream.eof())
    {
      Hit * hit = new Hit;
      stream >> *hit;

      return hit;
    }
    return nullptr;
}

bool LogReader::TrackNewFile(const string &path)
{
    CloseFileStream();

    stream.open(path, ios_base::in);

    return(stream.good());
}

void LogReader::CloseFileStream()
{
    if (stream.is_open())
        stream.close();
}

//-------------------------------------------- Constructeurs - destructeur

LogReader::LogReader(const string & path)
{
#ifdef MAP
    cout << "Appel au destructeur de <LogReader>" << endl;
#endif

    if (!TrackNewFile(path))
        throw invalid_argument("Error Opening File : " + path);
} //----- Fin de LogReader

LogReader::~LogReader()
{
#ifdef MAP
    cout << "Appel au constructeur de <LogReader>" << endl;
#endif
    CloseFileStream();
} //----- Fin de ~LogReader

//----------------------------------------------------- Méthodes protégées


/*************************************************************************
                           ArgumentParser  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

// Réalisation de la classe <ArgumentParser> (fichier ArgumentParser.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "ArgumentParser.h"

using namespace std;
//------------------------------------------------------------- Constantes

const regex ArgumentParser::commandRegex = regex("^(( -g \\S+\\.dot)|( -e)|( -t (2[0-3]|1?[0-9]))){0,3} \\S+\\.(txt|log) $");
const regex ArgumentParser::graphPathArgRegex = regex("\\S+\\.dot");
const regex ArgumentParser::timeArgRegex = regex("-t (2[0-3]|1?[0-9])");
const regex ArgumentParser::logPathArgRegex = regex("\\S+\\.(txt|log)");

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

bool ArgumentParser::Parse(string command, Analyse &analyse)
{
    if (!regex_match(command, commandRegex))
        return false;

    smatch match;

    if (regex_search(command, match, graphPathArgRegex))    //TODO: Add Cas use si multiple options
    {
        // analyse.SetGraphPath(match[0]);
    }

    if (regex_search(command, match, timeArgRegex))    //TODO: Add Cas use si multiple options
    {
        string path = match[0];
        size_t pos = path.find(' ');

        // analyse.SetHour(stoi(path.substr(pos)));
    }

    if (command.find("-e") != string::npos)
    {
        // analyse.SetExcludeResourcesFile(true);
    }

    if (regex_search(command, match, logPathArgRegex))
    {
        // LogReader * logReader = LogReader::GetInstance();
    }

    return false;
}

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
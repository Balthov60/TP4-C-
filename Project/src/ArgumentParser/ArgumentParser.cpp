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

const regex ArgumentParser::commandRegex        = regex(R"(^(( -g \S+\.dot)|( -e)|( -t [0-9]+)){0,3} \S+\.(txt|log) $)");
const regex ArgumentParser::graphPathArgRegex   = regex("\\S+\\.dot");
const regex ArgumentParser::timeArgRegex        = regex("-t [0-9]+");
const regex ArgumentParser::logPathArgRegex     = regex("\\S+\\.(txt|log)");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool ArgumentParser::Parse(string &command, Analyse &analyse)
{
    if (!regex_match(command, commandRegex))
        return false;

    smatch match;

    if (!testTimeArgs(command, analyse))
        return false;

    if (!testGraphArgs(command, analyse))
        return false;

    if (command.find("-e") != string::npos)
    {
        analyse.SetExcludeResourcesFile(true);
    }

    return testLogArgs(command, analyse);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool ArgumentParser::testTimeArgs(string &command, Analyse &analyse)
{
    smatch match;

    if (regex_search(command, match, timeArgRegex))
    {
        string args = match[0];
        size_t pos = args.find(' ');
        int hour;

        try
        {
            hour = stoi(args.substr(pos));
        }
        catch(exception & e)
        {
            return false;
        }

        if (hour < 0 || hour > 23)
        {
            cout << "L'heure doit être un entier compris entre 0 et 23." << endl;
            return false;
        }

        analyse.SetHour(hour);
    }

    return true;
}

bool ArgumentParser::testGraphArgs(string &command, Analyse &analyse)
{
    smatch match;

    if (regex_search(command, match, graphPathArgRegex))
    {
        string args = match[0];
        size_t pos = args.find(' ');

        string path = args.substr(pos);

        ifstream fileExistStream(path);
        if (fileExistStream.good())
        {
            fileExistStream.close();

            if (askForFileOverride())
            {
                analyse.SetGraph(command);
                return true;
            }
            else
            {
                return false;
            }
        }

        ofstream fileCanBeCreatedStream(path);
        if (fileCanBeCreatedStream.good())
        {
            analyse.SetGraph(path);
        }
    }

    return true;
}
bool ArgumentParser::askForFileOverride()
{
    for ( ; ; )
    {
        char r;
        cout << "Le fichier existe déjà, voulez vous l'écraser, (o/n) : ";
        cin >> r;

        if (r == 'o' || r == 'O')
            return true;

        if (r == 'n' || r == 'N')
            return false;
    }
}

bool ArgumentParser::testLogArgs(string &command, Analyse &analyse)
{
    smatch match;

    if (regex_search(command, match, logPathArgRegex))
    {
        LogReader * logReader;

        try
        {
            logReader = new LogReader(match[0]);
        }
        catch (exception & e)
        {
            cerr << "Impossible d'ouvrir le fichier demandé." << endl;
            return false;
        }

        analyse.SetLogReader(logReader);
        return true;
    }

    return true;
}
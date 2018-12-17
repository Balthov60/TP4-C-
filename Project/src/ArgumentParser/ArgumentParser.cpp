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

const regex ArgumentParser::commandRegex      = regex(R"(^(( -g \S+\.dot)|( -e)|( -t [0-9]+)){0,3} \S+\.(txt|log) $)");
const regex ArgumentParser::graphPathArgRegex = regex("\\S+\\.dot");
const regex ArgumentParser::timeArgRegex      = regex("-t [0-9]+");
const regex ArgumentParser::logPathArgRegex   = regex("\\S+\\.(txt|log)");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

PARSE_RESULTS ArgumentParser::Parse(string &args, Analyse &analyse) //TODO add another return type if file don't want to be override
{
    if (!regex_match(args, commandRegex))
        return PARSING_ERROR;

    if (!testTimeArgs(args, analyse))
        return INVALID_VALUE;

    if (!testGraphArgs(args, analyse))
        return FILE_NO_OVERRIDE;

    if (args.find("-e") != string::npos)
        analyse.SetExcludeResourcesFile(true);

    if (!testLogArgs(args, analyse))
        return FILE_NOT_FOUND;

    return GOOD;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool ArgumentParser::testTimeArgs(string &args, Analyse &analyse)
{
    smatch match;

    if (regex_search(args, match, timeArgRegex))
    {
        string arg = match[0];
        size_t pos = arg.find(' ');
        int hour;

        try
        {
            hour = stoi(arg.substr(pos));
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

bool ArgumentParser::testGraphArgs(string &args, Analyse &analyse)
{
    smatch match;

    if (regex_search(args, match, graphPathArgRegex))
    {
        string path = match[0];

        ifstream fileExistStream(path);
        if (fileExistStream.good())
        {
            fileExistStream.close();

            if (askForFileOverride())
            {
                analyse.SetGraph(path);
                return true;
            }
            else
            {
                cout << "Analyse de log annulé, veuillez choisir un autre fichier pour le graph ou désactiver cette option.";
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

bool ArgumentParser::testLogArgs(string &args, Analyse &analyse)
{
    smatch match;

    if (regex_search(args, match, logPathArgRegex))
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
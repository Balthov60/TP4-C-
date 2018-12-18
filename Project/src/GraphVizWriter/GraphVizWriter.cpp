/*************************************************************************
                           GraphVizWriter  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

// Réalisation de la classe <GraphVizWriter> (fichier GraphVizWriter.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "GraphVizWriter.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool GraphVizWriter::Write(unordered_map<string, unsigned int> &nodeCounterMap, GraphMapper &graphMapper, string &path)
{
    ofstream stream(path);
    if (!stream.good())
        return false;

    stream << "digraph {" << endl;

    for (auto &it : nodeCounterMap)
    {
        stream << "ID" << &it.first << " [label=\"" << it.first << "\"];" << endl;
    }

    for (auto &it : graphMapper)
    {
        stream << "ID" << it.first.first << " -> " << "ID" << it.first.second << " [label=\"" << it.second << "\"];" << endl;
    }

    stream << "}" << endl;

    return true;
}

/*************************************************************************
                           Analyse  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//------ Réalisation de la classe <Analyse> (fichier Analyse.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Analyse.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Analyse::Run()
{
    while(analyseNextLog());

    generateOrderedNodeCounterMap();

    if (generateGraph)
    {
        if (GraphVizWriter::Write(graphMapper, graphPath))
            cout << "Le Fichier WizGraph a bien été généré." << endl;
        else
            cout << "Le Fichier WizGraph n'a pas pu être généré." << endl;
    }
    displayResult();

}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse():hour(-1), excludeResourcesFile(false), generateGraph(false)
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyse>" << endl;
#endif
} //----- Fin de Analyse


Analyse::~Analyse()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
bool Analyse::analyseNextLog()
//Algorithme :
//
{
    Hit * hitPtr;
    hitPtr = logReader->ReadNext();

    if (hitPtr)
    {
        if ((hour == -1 || (hitPtr->getDatetime().GetHour() == hour))
                && (!excludeResourcesFile || (excludeResourcesFile && !hitPtr->isRelatedToResourceFile())))
        {
            string url = hitPtr->getRequest().getUrl();

            //Register hits info in node counter map
            auto nodeCounterResult = nodeCounterMap.find(url);

            if (nodeCounterResult != nodeCounterMap.end())
            {
                (nodeCounterResult->second)++;
            }
            else
            {
                nodeCounterMap.insert({url, 1});
                nodeCounterResult = nodeCounterMap.find(url);
            }

            if (generateGraph)
            {
                string referer = hitPtr->getReferer();
                const string * ptrToUrl = &nodeCounterResult->first;

                auto graphMapperResult = graphMapper.find(pair<const string *, string>(ptrToUrl, referer));
                if (graphMapperResult != graphMapper.end())
                {
                    (graphMapperResult->second)++;
                }
                else
                {
                    graphMapper.insert({pair<const string *,string>(ptrToUrl,referer),1});
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Analyse::generateOrderedNodeCounterMap()
{
    for (auto it = nodeCounterMap.begin(); it != nodeCounterMap.end(); it++)
    {
        orderedNodeCounterMap.insert({it->second, &(it->first)});
    }
}

void Analyse::displayResult()
{
    unsigned int i = 1;

    for (auto it = orderedNodeCounterMap.rbegin(); it != orderedNodeCounterMap.rend() && i <= 10; it++)
    {
        cout << i << " - Cible : " << *(*it).second << " : " << (*it).first << " visite(s)" << endl;
        i++;
    }

}

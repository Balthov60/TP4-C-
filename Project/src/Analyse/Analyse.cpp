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
        if (GraphVizWriter::Write(nodeCounter, graphMapper, graphPath))
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
{
    Hit * hitPtr;
    hitPtr = logReader->ReadNext();

    if (hitPtr)
    {
        if ((hour == -1 || (hitPtr->getDatetime().GetHour() == hour)) && (!excludeResourcesFile || !hitPtr->isRelatedToResourceFile()))
        {
            auto node = updateNodeCounterMapWith(hitPtr->getRequest().getUrl());

            if (generateGraph)
            {
                const string * ptrToUrl = &(node->first);

                //adding referer url to nodeCounter to register its string if it doesn't already exist
                string referer = hitPtr->getReferer();
                auto nodeCounterResultReferer = nodeCounter.find(referer);

                if (nodeCounterResultReferer == nodeCounter.end()) {
                    nodeCounter.insert({referer, 0});
                }
                const string * ptrToReferer = &nodeCounterResultReferer->first;

                //adding the pair of pointer to target URL and referer URL in graphMapper map
                auto graphMapperResult = graphMapper.find(pair<const string *, const string *>(ptrToReferer, ptrToUrl));
                if (graphMapperResult != graphMapper.end())
                {
                    (graphMapperResult->second)++;
                }
                else
                {
                    graphMapper.insert({pair<const string *,const string *>(ptrToReferer, ptrToUrl), 1});
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
NodeCounter::iterator Analyse::updateNodeCounterMapWith(const string &url)
{
    auto nodeCounterResultUrl = nodeCounter.find(url);

    if (nodeCounterResultUrl != nodeCounter.end())
    {
        (nodeCounterResultUrl->second)++;
    }
    else
    {
        nodeCounter.insert({url, 1});
        nodeCounterResultUrl = nodeCounter.find(url);
    }

    return nodeCounterResultUrl;
}

void Analyse::generateOrderedNodeCounterMap()
{
    for (auto it = nodeCounter.begin(); it != nodeCounter.end(); it++)
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

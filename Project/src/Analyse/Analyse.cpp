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
            const string * url = updateNodeCounterMapWithUrl(hitPtr->getRequest().getUrl());

            if (generateGraph)
            {
                const string * referer = getRefererStringInNodeCounterMap(hitPtr->getReferer());
                updateGraphMapper(referer, url);

                delete hitPtr;
            }
        }
        
        return true;
    }

    return false;
}
const string * Analyse::updateNodeCounterMapWithUrl(const string &url)
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

    return &(nodeCounterResultUrl->first);
}
const string * Analyse::getRefererStringInNodeCounterMap(const string &referer)
{
    auto nodeReferer = nodeCounter.find(referer);

    if (nodeReferer == nodeCounter.end()) {
        nodeReferer = nodeCounter.insert({referer, 0}).first;
    }
    const string * ptrToReferer = &(nodeReferer->first);

    return &(nodeReferer->first);
}
void Analyse::updateGraphMapper(const string * referer, const string * url)
{
    auto graphMapperResult = graphMapper.find(pair<const string *, const string *>(referer, url));
    if (graphMapperResult != graphMapper.end())
    {
        (graphMapperResult->second)++;
    }
    else
    {
        graphMapper.insert({pair<const string *,const string *>(referer, url), 1});
    }
}

void Analyse::generateOrderedNodeCounterMap()
{
    for (auto &it : nodeCounter)
    {
        orderedNodeCounterMap.insert({it.second, &(it.first)});
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

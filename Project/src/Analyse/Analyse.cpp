/*************************************************************************
                           Analyse  -  description
                             -------------------
    début                : 11/12/2018
    copyright            : (C) 2018 par Valentin Gilles et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------

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
//Algorithme :
//
{
    while(analyseNextLog());
    generateOrderedNodeCounterMap();
    displayResult();
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse():hour(-1), excludeResourcesFile(false), generateGraph(false)
// Algorithme :
//
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

        if ( (hour==-1 || (hitPtr->getDatetime().GetHour() == hour))
                && (!excludeResourcesFile || (excludeResourcesFile && !hitPtr->isRelatedToResourceFile()))){

            string url = hitPtr->getRequest().getUrl();

            //Register hits info in node counter map
            auto nodeCounterResult = nodeCounterMap.find(url);
            if (nodeCounterResult != nodeCounterMap.end()) {
                (nodeCounterResult->second)++;
            } else {
                nodeCounterMap.insert({url,1});
                nodeCounterResult = nodeCounterMap.find(url);
            }

            //If needed, adding information in graph mapper
            if (generateGraph){
                string referer = hitPtr->getReferer();
                const string * ptrToUrl = &nodeCounterResult->first;
                auto graphMapperResult = graphMapper.find(pair<const string * , string>(ptrToUrl,referer));
                if (graphMapperResult != graphMapper.end()){
                    (graphMapperResult->second)++;
                } else {
                    graphMapper.insert({pair<const string *,string>(ptrToUrl,referer),1});
                }
            }
        }
        return true;
    } else {
        return false;
    }
} //---- Fin de analyseNextLog

void Analyse::generateOrderedNodeCounterMap()
//Algorithme :
//
{
    unordered_map<string,unsigned int>::iterator uMapIterator;
    const string * ptrToUrl;
    for(uMapIterator = nodeCounterMap.begin(); uMapIterator != nodeCounterMap.end(); uMapIterator++){
        ptrToUrl = &uMapIterator->first;
        orderedNodeCounterMap.insert({uMapIterator->second,ptrToUrl});
    }
} // ---- Fin de generateOrderedNodeCounterMap

void Analyse::generateGraphMapper()
//Algorithme :
//
{

} // ---- Fin de generateGraphMapper

void Analyse::displayResult()
//Algorithme :
//
{
    multimap<unsigned int, const string *>::reverse_iterator reverseIterator;
    unsigned int i=1;

    for (reverseIterator = orderedNodeCounterMap.rbegin(); reverseIterator != orderedNodeCounterMap.rend() && i<=10; reverseIterator++){
        cout << i << " - Cible : " << *reverseIterator->second << " : " << reverseIterator->first << " visite";
        (reverseIterator->first > 1 ? cout << "s"<< endl : cout << endl);
        i++;
    }

    unordered_map<pair<const string *,string>,unsigned int,pairhash>::iterator it;

    for (it = graphMapper.begin() ; it != graphMapper.cend() ; it++){
        cout << "From " << it->first.second << " to " << *(it->first.first) << " : " << it->second << " fois." << endl;
    }

} // ---- Fin de display result

#include <iostream>
#include <string>
#include <iomanip>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

using namespace std;

int main(int argc, char *argv[])
{
    Analyse analyse;
    string command = " ";

    for (int i = 1; i < argc; i++)
        command.append(argv[i]).append(" ");

    if (ArgumentParser::Parse(command, analyse))
    {
        analyse.Run();
    }
    else
    {
        cout                                                                                            << endl;
        cout << "Format de la commande non valide..."                                                   << endl;
        cout                                                                                            << endl;
        cout << "Utilisation de ./analog [-e|-g|-t] <path>"                                             << endl;
        cout << "   <path>        : chemin vers un fichier d’extension .txt ou .log."                   << endl;
        cout << "   -e            : Exclut les documents de type image, css ou javascript."             << endl;
        cout << "   -g <path.dot> : Genère le fichier <path.dot> au format GraphViz du graphe analysé." << endl;
        cout << "   -t [0-23]     : Prend en compte que les hits dans le créneau horaire [t, t+1]."     << endl;
        cout                                                                                            << endl;
    }

    return 0;
}
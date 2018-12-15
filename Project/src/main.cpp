#include <iostream>
#include <string>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    Analyse analyse;
    string command = " ";

    for (int i = 1; i < argc; i++)
        command.append(argv[i]).append(" ");

    cout << "Command : \"" << command << "\"" << endl;

    if (!ArgumentParser::Parse(command, analyse))
    {
        cout                                                                                                                    << endl;
        cout << "Format de la commande non valide..."                                                                           << endl;
        cout                                                                                                                    << endl;
        cout << "Utilisation de ./analog [-e|-g|-t] <path>"                                                                     << endl;
        cout << "   <path>"        << setw(10) << " : " << "chemin vers un fichier d’extension .txt ou .log."                   << endl;
        cout << "   -e"            << setw(14) << " : " << "Exclut les documents de type image, css ou javascript."             << endl;
        cout << "   -g <path.dot>" << setw(3)  << " : " << "Genère le fichier <path.dot> au format GraphViz du graphe analysé." << endl;
        cout << "   -t [0-23]"	   << setw(7)  << " : " << "Prend en compte que les hits dans le créneau horaire [t, t+1]."     << endl;
        cout                                                                                                                    << endl;
    }

    return 0;
}
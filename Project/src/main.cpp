#include <iostream>
#include <string>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, char *argv[])
{
    Analyse analyse;
    string command = " ";

    for (int i = 1; i < argc; i++)
        command.append(argv[i]).append(" ");

    cout << "Command : \"" << command << "\"" << endl;

    if (ArgumentParser::Parse(command, analyse))
        return 1;

    try
    {
        logReader = new LogReader("../anonyme copie.log");
    }
    catch (exception & e)
    {
        cerr << e.what();
        delete logReader;
        return 1;
    }

    return 0;
}
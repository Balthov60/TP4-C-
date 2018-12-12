#include <iostream>
#include <string>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

int main(int argc, char *argv[])
{
    Analyse analyse;
    string command = " ";

    for (int i = 1; i < argc; i++)
        command.append(argv[i]).append(" ");

    cout << "Command : \"" << command << "\"" << endl;

    if (ArgumentParser::Parse(command, analyse))
        return 1;

    return 0;
}
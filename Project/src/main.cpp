#include <iostream>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, char *argv[])
{
    Analyse analyse;
    LogReader * logReader;

    if (ArgumentParser::Parse(argc, argv, analyse));

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

    int i = 0;
    Hit * hit;
    while ((hit = logReader->ReadNext()) != nullptr)
    {
        cout << i << " " << hit->getIp() << endl;
        i++;
    }

    cout << i << endl;
    delete logReader;

    return 0;
}
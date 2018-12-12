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

    if (ArgumentParser::Parse(argc, argv, analyse));

    return 0;
}
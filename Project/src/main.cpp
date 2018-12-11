#include <iostream>

#include "ArgumentParser/ArgumentParser.h"
#include "Analyse/Analyse.h"

int main(int argc, char *argv[])
{
    Analyse analyse;

    if (ArgumentParser::Parse(argc, argv, analyse));

    return 0;
}
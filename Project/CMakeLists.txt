cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project src/main.cpp src/Analyse/Analyse.h src/ArgumentParser/ArgumentParser.h src/Datetime/Datetime.h
               src/GraphVizWriter/GraphVizWriter.h src/Hit/Hit.h src/LogReader/LogReader.h src/Request/Request.h)
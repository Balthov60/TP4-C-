cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project src/main.cpp src/Analyse/Analyse src/ArgumentParser/ArgumentParser src/Datetime/Datetime
               src/GraphVizWriter/GraphVizWriter src/Hit/Hit src/LogReader/LogReader src/Request/Request)

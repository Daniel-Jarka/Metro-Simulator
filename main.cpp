/*
 *  main.cpp
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file contains the driver that interacts with the user
 *  and the MetroSim class.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
        if (argc < 3 or argc > 4) {
                std::cerr << "Usage: ./MetroSim stationsFile" 
                          << "outputFile [commandsFile]" << '\n';
                exit(EXIT_FAILURE);
        }
        std::ostream& output = std::cout;
        MetroSim sim(argv[1]);
        if (argc == 4) {
            sim.createSim(output, argv[2], argv[3]);
        }
        else {
            sim.createSim(output, argv[2], "");
        }
        return 0;
}

/*
 *  MetroSim.h
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1 MetroSim
 *
 *  MetroSim is a class that represents the simulation
 *  using PassengerQueues. The passengers at each station
 *  are represented by a queue, and the passengers on the train
 *  are also represented by a queue. An instance of MetroSim must
 *  be initialized with at least two stations. MetroSim reads in a 
 *  file of stations that will be used to represent station names.
 *  MetroSim outputs the information associated with departing 
 *  passengers to an output file. Commands can be given to MetroSim
 *  either through manual user input (cin), or through a commands file. 
 *  The train and stations are implemented using std::vector by storing
 *  each queue as an element in the vector.
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "Passenger.h"
#include "PassengerQueue.h"
using namespace std;


class MetroSim
{

public:
    MetroSim(std::string filename);
    void createSim(std::ostream &output, std::string outFile, 
                                        std::string commands);

private:
    struct Station {
        std::string name;
        int number;
        PassengerQueue people;
    };
    int train_loc;
    std::vector<Station> stations;
    std::vector<PassengerQueue> train;
    void printSim(std::ostream &output);
    void mm(std::ostream &outFile);
    void printTrain(std::ostream &output, int location);
    void readCommands(std::istream &input, std::ostream &output, 
                                            std::ostream &outFile);
    bool noCommands(std::string filename);
    void printPassenger(std::ostream &outFile, std::string station, 
                                                        int pass_id);
    int getDestination(int location);
    Passenger getFirst(int location);

};

#endif

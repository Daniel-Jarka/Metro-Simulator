/*
 *  MetroSim.cpp
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file contains the implementation of the
 *  MetroSim class.
 *
 */

#include "MetroSim.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * name:      MetroSim( )
 * purpose:   This is the constructor for MetroSim that initializes
 *            a MetroSim object with a file
 * arguments: a string that represents a file name
 * returns:   none
 * effects:   Constructs a Metro Simulation with the provided information.
 */
MetroSim::MetroSim(std::string filename) {
    this->train_loc = 0;
    std::ifstream infile(filename);
    if (infile.fail()) {
        std::cerr << "Error: could not open file " << filename << '\n';
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while(not(infile.eof())) {
        std::string line_name;
        std::getline(infile, line_name);
        if (not(line_name == "")) {
            Station new_station;
            new_station.name = line_name;
            new_station.number = count;
            PassengerQueue new_queue;
            new_station.people = new_queue;
            stations.push_back(new_station);
            train.push_back(new_queue);
            ++count;
        }
    }
    infile.close();
}

/*
 * name:      createSim( )
 * purpose:   This function checks if there is a command file and
 *            accordingly passes either a cin or ifstream object
 *            to readCommands.
 * arguments: an ostream where std::cout output is directed to,
 *            a string that represents the name of an output file,
 *            and a string that represents the name of a commands
 *            file.
 * returns:   none
 * effects:   Opens an output file and conditionally opens an
 *            input file if there is a commands file passed. 
 */
void MetroSim::createSim(std::ostream &output, std::string outFile, 
                                               std::string commands) {
    std::ofstream outfile(outFile);
    if (outfile.fail()) {
        std::cerr << "Error: could not open file " << outFile << '\n';
        exit(EXIT_FAILURE);
    }
    if (noCommands(commands)) {
        readCommands(cin, output, outfile);
    }
    else {
        std::ifstream infile(commands);
        if (infile.fail()) {
            std::cerr << "Error: could not open file " << commands << '\n';
            exit(EXIT_FAILURE);
        }
        readCommands(infile, output, outfile);
        infile.close();
    }
    outfile.close();
}

/*
 * name:      printSim( )
 * purpose:   This function prints the current state of the MetroSim simulation
 * arguments: an ostream object used to direct output to the terminal. 
 * returns:   none
 * effects:   Updates the output representation of MetroSim in the terminal.
 */
void MetroSim::printSim(std::ostream &output) {
    // passengers
    int train_length = train.size();
    output << "Passengers on the train: "
    << "{";
    for (int i = 0; i < train_length; ++i) {
        train.at(i).print(output);
    }
    output << "}" << '\n';

    // stations
    int const_size = stations.size();
    for(int i = 0; i < const_size; ++i) {
        printTrain(output, i);
        output << (stations.at(i).number)
        << "] " << (stations.at(i).name) << " {"; 

        stations.at(i).people.print(output);

        output << "}" << '\n';
    }
}

/*
 * name:      mm( )
 * purpose:   Moves the train and accordingly queues boarding passengers
 *            and dequeues departing passengers. 
 * arguments: an ostream object used to send departing passengers' info
 *            to an output file.
 * returns:   none
 * effects:   Queues boarding passengers to the train vector and dequeues
 *            those passengers from their station. Dequeues departing 
 *            passengers from the train and removes them from the simulation.
 */
void MetroSim::mm(std::ostream &outFile) {
    if (stations.at(train_loc).people.size() > 0) {
        int const_size = stations.at(train_loc).people.size();
        for (int i = 0; i < const_size; ++i) {
            // enqueues passenger to the train car that corresponds with
            // the passenger's departing station.
            train.at(getDestination(train_loc)).enqueue(getFirst(train_loc));
            stations.at(train_loc).people.dequeue();
        }
    }
    this->train_loc++;
    if (this->train_loc == stations.back().number + 1) {
        this->train_loc = 0;
    }
    if (train.at(train_loc).size() > 0) {
        int const_size = train.at(train_loc).size();
        // Check if any passengers are getting off at the current station
        if (train.at(train_loc).front().getEndingStation() == train_loc) {
            for (int i = 0; i < const_size; ++i) {
                std::string departure = stations.at(train_loc).name;
                int id = train.at(train_loc).front().getId();
                printPassenger(outFile, departure, id);
                train.at(train_loc).dequeue();
            }
        }
    }
}

/*
 * name:      printPassenger( )
 * purpose:   This function prints the passenger id and departing station
 *            of each passenger to an outputfile.
 * arguments: an ostream object that represents the file to send output to,
 *            a string that represents station name, and an integer that 
 *            represents a passenger's id.
 * returns:   none
 * effects:   Directs output to an output file.
 */
void MetroSim::printPassenger(std::ostream &outFile, std::string station, 
                                                                int pass_id) {
    outFile << "Passenger " << pass_id << " left train at station " << station
            << '\n';
}

/*
 * name:      noCommands( )
 * purpose:   This function checks if the commands parameter is empty.
 * arguments: a string that represents a command file name
 * returns:   true if the command file is empty, false otherwise.
 * effects:   none
 */
bool MetroSim::noCommands(std::string filename) {
    return filename.empty();
}

/*
 * name:      readCommands( )
 * purpose:   This function receives input commands and manipulates the
 *            program based on those inputs. 
 * arguments: an istream object than can either be cin or an ifstream file,
 *            an ostream output object to send output to the terminal, and
 *            an ostream outFile object to send passenger output to an output
 *            file.
 * returns:   none
 * effects:   Manipulates the simulation based on entered commands. Can end
 *            the program, add passengers, or move metro.
 */
void MetroSim::readCommands(std::istream &input, std::ostream &output, 
                                                std::ostream &outFile) {
    string p, end;
    int s, f;
    int num_passengers = 0;
    while (true) {
        printSim(output);
        output << "Command? ";
        input >> p;
        if (p[0] == '\0') {
            break;
        }
        if (p == "p") {
            input >> s >> f;
            ++num_passengers;
            Passenger new_pass(num_passengers, s, f);
            stations.at(s).people.enqueue(new_pass);
        }
        else if(p == "m") {
            input >> end;
            if(end == "m") {
                mm(outFile);         
            }
            else if (end == "f") {
                break;
            }
        }
        else {
            output << "Try again." << endl;
        }
    }
    output << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/*
 * name:      printTrain( )
 * purpose:   This function correctly prints the location of the train
 *            in the simulation.
 * arguments: an ostream object that sends output to the terminal and
 *            an integer that represents the train's location.
 * returns:   none
 * effects:   none
 */
void MetroSim::printTrain(std::ostream &output, int location) {
    if (location == this->train_loc) {
        output << "TRAIN: [";
    }
    else {
        output << "       [";
    }
}

/*
 * name:      getDestination( )
 * purpose:   This helper function reduces clutter returns
 *            the destination of a particular passenger.
 * arguments: an integer that represents the number of a particular station.
 * returns:   an integer that represents the destination of a passenger at the
 *            front of the queue of a station.
 * effects:   none
 */
int MetroSim::getDestination(int location) {
    return stations.at(location).people.front().getEndingStation();
}

/*
 * name:      getFirst( )
 * purpose:   This helper function reduces clutter and returns the passenger
 *            at the front of a queue.
 * arguments: an integer that represents the number of a particular station.
 * returns:   a Passenger at the front of the queue of a station.
 * effects:   none
 */
Passenger MetroSim::getFirst(int location) {
    return stations.at(location).people.front();
}
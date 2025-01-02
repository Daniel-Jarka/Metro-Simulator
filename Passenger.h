/*
 *  Passenger.h
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1: Metro Simulator
 *
 * Passenger is a class that is used to represent the data
 * stored for an instance of a Passenger. Passengers
 * are identified by an ID, a boarding station, and
 * a departing station. 
*/

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

class Passenger {
   public:
    Passenger(int id, int startingStation, int endingStation);
    int getId();
    int getStartingStation();
    int getEndingStation();
    void print(std::ostream &output);

   private:
    int id;
    int startingStation;
    int endingStation;
};

#endif


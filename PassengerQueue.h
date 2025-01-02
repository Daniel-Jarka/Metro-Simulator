/*
 *  PassengerQueue.h
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1: Metro Simulator
 *
 * PassengerQueue is a class that represents a linked list of 
 * Passengers that is implemented in the format of a queue. 
 * PassengerQueues begin empty. Because this class represents
 * a queue, clients can only add to the back of the list and 
 * remove from the front of the list. The list is implemented 
 * using std::list and the standard functions that come with
 * this library.
*/

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include <string>
#include <list>
#include "Passenger.h"

using namespace std;

class PassengerQueue {
   public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);
   private:
    std::list<Passenger> passengers;

};

#endif
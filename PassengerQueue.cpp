/*
 *  PassengerQueue.cpp
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1: Metro Simulator
 *
 *  This file contains the implementation of the
 *  PassengerQueue class.
*/
#include "PassengerQueue.h"

#include <iostream>
#include <string>

/*
 * name:      front
 * purpose:   This function returns the Passenger at the front
 *            of the queue in the current instance.
 * arguments: none
 * returns:   The Passenger at the front of the queue.
 * effects:   none
 */
Passenger PassengerQueue::front() {
    if(passengers.empty()) {
        throw runtime_error("cannot get first of empty Queue");
    }
    return passengers.front();
}

/*
 * name:      dequeue
 * purpose:   This function removes the passenger at the front
 *            of the queue from the queue.
 * arguments: none
 * returns:   none
 * effects:   Shortens the queue by one and sets the previously
 *            second passenger in the queue to the front of the 
 *            queue.
 */
void PassengerQueue::dequeue() {
    if(passengers.empty()) {
        throw runtime_error("cannot remove from empty Queue");
    } 
    passengers.pop_front();
}

/*
 * name:      enqueue
 * purpose:   This function adds a new passenger to the back
 *            of the queue.
 * arguments: a passenger to add to the queue.
 * returns:   none
 * effects:   Increases the queue by one and adds a passenger
 *            to the back of the queue.
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengers.push_back(passenger);
}

/*
 * name:      size
 * purpose:   This function returns the current size of the
 *            queue.
 * arguments: none
 * returns:   An integer that represents the current size of 
 *            the queue.
 * effects:   none
 */
int PassengerQueue::size() {
    return passengers.size();
}

/*
 * name:      print
 * purpose:   This function prints the ID, boarding station,
 *            and departing station of each passenger in the
 *            queue.
 * arguments: an ostream object that is used to print
 *            the data represented by a PassengerQueue.
 * returns:   none 
 * effects:   none
 */
void PassengerQueue::print(std::ostream &output) {
    for(std::list<Passenger>::iterator it = passengers.begin(); 
                                it != passengers.end(); ++it) {
        it->print(output);
    }
}
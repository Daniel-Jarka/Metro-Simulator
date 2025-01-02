/*
 *  unit_tests.h
 *  Daniel Jarka
 *  9/28/24
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Uses Matt Russell's unit_test framework to 
 *  test the Passenger and PassengerQueue classes.
 */

#include "PassengerQueue.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void dummy_test() {}

void passenger_queue_constructor_test() {
    PassengerQueue new_queue;
}

void add_queue_test() {
    PassengerQueue new_queue;
    Passenger new_passenger(1, 2, 3);
    Passenger sec_passenger(2, 2, 4);
    new_queue.enqueue(new_passenger);
    new_queue.enqueue(sec_passenger);
    assert(new_queue.front().getId() == 1);
    assert(new_queue.front().getStartingStation() == 2);
    assert(new_queue.front().getEndingStation() == 3);
}

void remove_queue_test() {
    PassengerQueue new_queue;
    Passenger new_passenger(1, 2, 3);
    Passenger sec_passenger(2, 2, 4);
    new_queue.enqueue(new_passenger);
    new_queue.enqueue(sec_passenger);
    new_queue.dequeue();
    assert(new_queue.front().getId() == 2);
    assert(new_queue.front().getStartingStation() == 2);
    assert(new_queue.front().getEndingStation() == 4);
}

void queue_size_test() {
    PassengerQueue new_queue;
    Passenger new_passenger(1, 2, 3);
    Passenger sec_passenger(2, 2, 4);
    new_queue.enqueue(new_passenger);
    new_queue.enqueue(sec_passenger);
    new_queue.enqueue(sec_passenger);
    new_queue.enqueue(sec_passenger);
    new_queue.enqueue(new_passenger);
    assert(new_queue.size() == 5);
}

void passenger_print_test() {
    std::ostream& output = std::cout;
    PassengerQueue new_queue;
    Passenger new_passenger(1, 2, 3);
    Passenger sec_passenger(2, 2, 4);
    Passenger thd_passenger(3, 5, 10);
    new_queue.enqueue(new_passenger);
    new_queue.enqueue(sec_passenger);
    new_queue.enqueue(thd_passenger);
    new_queue.print(output);
}


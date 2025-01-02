/******************************************************************************
* Project 1: Metro Simulator
* CS 15
* README
* Author: Daniel Jarka djarka01
******************************************************************************/

B. Program Purpose:

     This program is designed to simulate a simple representation
     of a train picking up and dropping off passengers at different
     train stations. This program particularly demonstrates how a queue 
     is a useful implementation of a list to represent a "first come, 
     first serve" order of adding and removing elements from a list.
     Additionally, the client has access too much fewer member functions
     of the MetroSim class, since the purpose of this program for a client
     is akin to a game. A client will run the program and their only
     options for manipulating the program are by running the specific
     commands that change the state of the simulation. To that end,
     the client can move the train, add passengers to any station,
     and terminate the program. For each command run by the client,
     the program will print an updated representation of the simulation
     to std::out. Additionally, the program prints the information
     of each departing passenger to an output file. Finally,
     the program can accept an optional commands file parameter
     that reads input directly from a file instead of a user. 


C. Acknowledgements: 

     I consulted https://cplusplus.com/reference/vector/vector/
     and https://cplusplus.com/reference/list/list/ to learn how
     to implement and use std::vector and std:list. 

     I used https://cplusplus.com/reference/string/string/
     to look for some useful functions for strings (I used empty()).

     I looked at https://cplusplus.com/reference/ostream/ostream/
     to learn more about ostreams.


D. Files: 

     Passenger.cpp:
          Implementation of Passenger class. Used to represent
          each individual passenger at the stations or on the train
          in MetroSim.

     Passenger.h:
          Interface of Passenger class.

     PassengerQueue.cpp:
          Implementation of PassengerQueue class. Used to represent
          the line of passengers waiting to board/depart the train
          in a queue style format.

     PassengerQueue.h:
          Interface of PassengerQueue.

     unit_test.h:
          A unit testing file for the Passenger and PassengerQueue Classes.
          Runs in conjunction with the unit_test framework 
          to allow for testing of individual functions.

     Makefile:
          File used to run the "make" command which compiles and builds
          the program.
     
     MetroSim.cpp:
          Implementation of MetroSim class. Used to build the front-end
          interface and link it to the back-end functions to create 
          a proper metro simulation. 
     
     MetroSim.h:
          Interface of MetroSim class.

     main.cpp:
          Driver file which interacts with the user, the PassengerQueue class
          and the Passenger class.
     
     stations.txt:
          Test input data.

     test_stations1.txt:
          Test input data. Run with test_commands1.txt only.

     test_stations2.txt:
          Test input data. Run with test_commands1.txt only.

     test_commands.txt:
          Test input data.

     test_commands1.txt:
          Test input data.

     test_commands2.txt:
          Test input data.

     README: 
          This file.

E. Compile/run:
     - Compile using
            make MetroSim
     - run executable with
            ./MetroSim stationsFile passFile [commands]

F. Architechtural Overview:

     The backbone of this implementation relies on the Passenger and 
     PassengerQueue classes. The PassengerQueue is a queue that stores
     Passengers in a std::vector which allows the program to pop elements
     from the front and add elements to the back of the queue. The MetroSim
     class then uses two different std::vectors that contain PassengerQueues.

     The "train" in this implementation is a vector of PassengerQueues.
     Since passengers are ordered by their departing station, my train
     is initialized to have the same number of "cars" or queues as there
     are stations. When a passenger is added to the train from a station,
     the program uses the passenger's departing station to sort the
     passenger into the correct "car" or queue. For example,
     a passenger with a departing station "3" will be added to the
     third car of the train, which represents a queue of all passengers
     that have a departing station "3." Since each car is a queue,
     passengers are added and removed in order of their arrival. 

     Each "station" is implemented a little differently. First, the program 
     uses a struct to store station names and station numbers, as well as a
     PassengerQueue. This struct refers to one instance of a station, so each
     struct is then added to a vector of station structs. In this way, the
     program can keep track of the name and number of each station, as well
     as the passengers that are queued at each station. Unlike the train
     vector, passengers are added to a station queue based on their arriving
     station. For example, if a passenger is added to the simulation with
     arriving station "5," then this passenger is added to the queue that
     represents station number 5 in the stations vector. 



G. Data Structures: 

     The ADT here is a list, which is an ordered sequence of elements.
     There are two primary implementations of the list to run the program. 

     The main data structure is a queue, while the secondary data structure
     is a vector/array list. The primary role of the vector in this 
     implementation is to store different queues. The vector is useful because
     it allows for quick access to each queue. Since it is unreasonable for 
     a client to initialize an instance of MetroSim with billions of stations,
     the storage concern of using a vector/array list is practically 
     non-existent here. Of course, a client CAN initialize an instance of 
     MetroSim with billions of stations and potentially cause the computer 
     to run out of memory, but let'sassume this will not happen. 
     
     The queue is the main focus of this implementation because it is a useful 
     data structure to represent the removal/addition of elements in a 
     "first come, first serve" basis. Since passenger instances are waiting in
     a "line" to either board or depart the train, a queue is used for 
     elements that can only be added at the back and removed from the front. 
     Of course, there are other situations in which a queue data structure is 
     very useful. For example, a fast food restaurant with a mobile order
     feature will use a queue to show which order should be completed first.
     Any newly placed orders will be added to the back of the queue, since
     they are of least priority. Another example of a queue is when you
     want to purchase tickets for a concert on ticketmaster. Since there
     are a limited number of tickets, you are placed on a queue in order
     of who opened the web page first. You wait on the queue while the
     people in front of you purchase their tickets before you have your turn.
     (All of the tickets will probably be gone by then).

     Though queues are more "restricted" linked lists, this actually makes them
     very useful. Since there are very few operations you can perform to
     a queue, namely adding to the front and removing from the back,
     these operations are very fast. Because a queue is essentially a 
     linked list, memory is of relatively little concern as well. In this
     implementation, however, each queue is stored in a vector. While
     the queues themselves may not take up a lot of relative space for a large
     number of elements, the vectors can require a relatively larger amount
     of space for a very large number of queues to store. 

     While being a restricted linked list is an advantage, it can also be
     a disadvantage for a program that requires direct access to any
     element in the list. Queues should only be used for programs that
     need to represent a queue-like structure, otherwise they are difficult
     to work with. Be sure to stay away from queues if you need to operate
     on a list with anything other than popping from the front and adding to
     the back. 


    The ADT of this program is a list, which is an ordered sequence of elements.
    The main data structure of this homework is a Linked List, which 
    is a structure where each element points to another element in the list
    in an ordered sequence. This specific implementation is a doubly linked
    list, so each element actually points to the next and previous elements
    in the list. The advantage of using a Linked List is that the
    user does not have to worry about memory for very large lists as much
    as they would in an array list. This can be seen with any insertion 
    function,like insertAt() or pushAtBack(). Since data in this structure is 
    stored by pointers, the program only needs to find the correct location 
    in the list. At this point, it can create a new node without much trouble 
    or memory. This is unlike an array list, since the size of an array must 
    always be declared. This creates issues when a very large list is required,
    since our previous implementation of array lists doubled their capacity 
    whenever more space was needed. A disadvantage, however, is that adding 
    elements between the front and end of the list is not fast as it would be 
    in an array list. For example pushAtBack() takes time to find the last 
    position in the list because the elements stored in the list are not 
    contained within specifically known memory locations in the computer. 
    To find the last element, the program must traverse the list through n 
    elements to find the last element. So the big O complexity is O(n),
    which isn't actually as crazy as some other algorithms (not specifically
    in this implementation) can get!

    Algorithmically, there aren't any particularly complicated functions
    for queues. There really is just enqueue() and dequeue(), both of 
    which are O(1), since the program will always know where the front
    and back of the queue are. In MetroSim, however, mm() is O(n).
    Although the primary operation is still enqueue(), this operation
    can be called n times, since it depends on how many passengers are
    at a station. In any case, the O complexity of this program is 
    quite fast!


H. Testing:

     I used the unit_test framework to test the Passenger and PassengerQueue
     classes. I tested every function, particularly the functions
     I wrote for PassengerQueue, to make sure I'm in good shape for the
     rest of my MetroSim implementation.

     Testing MetroSim was a little more difficult, since I could not as
     easily use the unit_test framework. Instead, I used the_MetroSim
     as a reference and incrementally ran my own implementation with
     each function I completed. First I tested to see that my initial
     state of the program matched. Then I made sure that my "train"
     was printing correctly. Next, I made sure passengers were added 
     and printed correctly. I did this until I completed an implementation
     I felt confident in. At this point, I used the provided testing files
     to diff test my MetroSim with the_MetroSim. After passing this test,
     I created my own station and command files to try to go over as many
     different cases as possible. For example, using only two stations, 
     passing a file that does not exist, and ending the program before
     removing all passengers. 


I. Time Spent: 

     I spent about 8-9 hours on this assignment.

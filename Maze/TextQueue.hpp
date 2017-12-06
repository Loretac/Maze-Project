/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the member variables and function prototypes
 for the class Queue.
 *********************************************************************/

#ifndef TextQueue_hpp
#define TextQueue_hpp

#include <queue>
#include "Player.hpp"


using std::string;

class Queue
{
private:
    std::queue<string> myQueue;
    
public:
    Queue();
    void printQueue();
    void addToQueue(string);
};

#endif /* TextQueue_hpp */

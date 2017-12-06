/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Queue class contains all the notices the player receives while
 playing the game. They scroll upwards like a chat window. The
 queue is shown below the board throughout the entire game.
 *********************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "TextQueue.hpp"

using std::string;

/*********************************************************************
 Default constructor, initializes 5 "empty" lines with only borders
 and blank spaces.
 *********************************************************************/
Queue::Queue(){
    string empty = '|' + string(58, ' ') + '|';
    
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
}

/*********************************************************************
 This function adds a string to the back of the queue, while removing
 the first one. It also adds bordering lines so it remains visually
 consistent with the rest of the layout.
 *********************************************************************/
void Queue::addToQueue(string s){
    string currentString = "| ";
    currentString += s;
    
    currentString.resize(60, ' ');
    
    currentString[59] = '|';
    
    myQueue.push(currentString);
    myQueue.pop();
}

/*********************************************************************
 This function prints the contents of the queue.
 *********************************************************************/
void Queue::printQueue(){
    
    // clone the queue
    std::queue<string> tempQueue = myQueue;
    
    for(int i = 0; i < 5; i++){
        std::cout << tempQueue.front() << std::endl;
        tempQueue.pop();
    }
    std::cout << std::endl;
}

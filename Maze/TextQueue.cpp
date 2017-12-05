//
//  TextQueue.cpp
//  Maze
//
//  Created by Chris Loreta on 12/4/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include "TextQueue.hpp"

using std::string;

Queue::Queue(){
    string empty = '|' + string(58, ' ') + '|';
    
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
    myQueue.push(empty);
}

void Queue::addToQueue(string s){
    string currentString = "| ";
    currentString += s;
    
    currentString.resize(60, ' ');
    
    currentString[59] = '|';
    
    myQueue.push(currentString);
    myQueue.pop();
}

void Queue::printQueue(){
    // clone the queue
    
    std::queue<string> tempQueue = myQueue;
    
    for(int i = 0; i < 5; i++){
        std::cout << tempQueue.front() << std::endl;
        tempQueue.pop();
    }

    std::cout << std::endl;
}

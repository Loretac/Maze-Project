//
//  TextQueue.hpp
//  Maze
//
//  Created by Chris Loreta on 12/4/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

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

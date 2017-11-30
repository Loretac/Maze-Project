//
//  Space.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Space_hpp
#define Space_hpp

#include <iostream>

class Space{
protected:
    int position; // Where this space is
    char identity; // sample variable for testing
    Space *top;
    Space *right;
    Space *left;
    Space *bottom;
    
public:
    void setPosition(int);
    void setIdentity(char); // sample function for testing
    int getPosition();
    Space* getTop();
    Space* getRight();
    Space* getLeft();
    Space* getBottom();
    char getIdentity();
};

#endif /* Space_hpp */

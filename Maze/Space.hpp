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
private:
    int position; // Where this space is
    char identity; // sample variable for testing
    Space *top;
    Space *right;
    Space *left;
    Space *bottom;
    bool isOccupied;
    
    // Spaces which have been interacted with already (monsters killed) are switched to inactive
    bool isActive;
    
public:
    void setPosition(int);
    void setIdentity(char); // sample function for testing
    int getPosition();
    
    Space* getTop();
    Space* getRight();
    Space* getLeft();
    Space* getBottom();
    void setTop(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    void setBottom(Space*);
    void setTopNull();
    void setRightNull();
    void setLeftNull();
    void setBottomNull();
    char getIdentity();
    void setOccupied();
    void setUnoccupied();
    bool getActive();
    void setActive(bool);
    bool getOccupied();
    virtual bool precondition(int) = 0; // Before user chooses to move to a specific space
    virtual int postcondition() = 0;
};

#endif /* Space_hpp */

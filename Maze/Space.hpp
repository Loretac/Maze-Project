/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
This file contains the member variables and function prototypes for
 the Space class.
 *********************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <iostream>

class Space{
private:
    int position; // Position of space in 3x3 array (numbered 0-8)
    char identity; // sample variable for testing
    Space *top;
    Space *right;
    Space *left;
    Space *bottom;
    bool isOccupied;
    
    // Monster spaces that have been revealed but not attacked
    bool isDiscovered;
    
    // Spaces which have been interacted with already (monsters killed)
    // are switched to inactive
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
    bool getDiscovered();
    void setDiscovered(bool);
    virtual int precondition(int) = 0; // Before user chooses to move to a specific space
    virtual int postcondition() = 0; // After user completes move to space
};

#endif /* Space_hpp */

/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
Contains all the spaces. Has a print function for visualization.
 *********************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include "Free.hpp"

const int NUM_ROWS = 3;
const int NUM_COLS = 3;

class Board
{
private:
    // char array[NUM_ROWS][NUM_COLS];
    Space* array[9];
    int randA, randB, randC, randD, randE, randF, randG, randH, randI;
    Space *currentSpace; // keeps track of space occupied
    Monster *monster1;
    Monster *monster2;
    Monster *monster3;
    Pizza *pizza1;
    Delivery *deliv1;
    Random *r1;
    Random *r2;
    Random *r3;
    Free *free1;
    
public:
    Board(); // Constructor
    ~Board(); // Destructor
    void print();
    void randomize();
    Space* getCurrent();
    void setCurrent(Space*);
    void setPointers();
    void resetBoard(int);
    
};

#endif /* Board_hpp */

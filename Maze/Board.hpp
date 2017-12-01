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
    Space *currentSpace;
    
public:
    Board();
    ~Board();
    void print();
    void randomize();
    Space* getCurrent();
    void setCurrent(Space*);
};

#endif /* Board_hpp */

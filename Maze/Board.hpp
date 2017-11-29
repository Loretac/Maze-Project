/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 

 *********************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include "Space.hpp"

const int NUM_ROWS = 3;
const int NUM_COLS = 3;

class Board
{
private:

    char array[NUM_ROWS][NUM_COLS];
    
public:
    Board();
    void print();
};

#endif /* Board_hpp */

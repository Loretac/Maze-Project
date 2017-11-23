/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 

 *********************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <iostream>

const int NUM_ROWS = 30;
const int NUM_COLS = 80;

class Board
{
private:

    char array[NUM_ROWS][NUM_COLS];
    
public:
    Board();
    void print();
};

#endif /* Board_hpp */

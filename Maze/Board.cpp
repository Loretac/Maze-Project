/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
 
 *********************************************************************/

#include "Board.hpp"

using std::cout;
using std::endl;

Board::Board(){
    for(int row = 0; row < NUM_ROWS; row++){
        for(int column = 0; column < NUM_COLS; column++){
            array[row][column] = ' ';
            
            array[0][column] = '=';
            array[NUM_ROWS-1][column] = '=';
        }
        array[row][0] = '|';
        array[row][NUM_COLS-1] = '|';
    }
}

void Board::print(){
    for(int row = 0; row < NUM_ROWS; row++){
        for(int column = 0; column < NUM_COLS; column++){
            cout << array[row][column];
        }
        cout << endl;
    }
}

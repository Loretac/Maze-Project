/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
 
 *********************************************************************/

#include "Board.hpp"

using std::cout;
using std::endl;

Board::Board(){
    Monster monster1, monster2, monster3;
    Pizza pizza1;
    Delivery deliv1;
    Random r1, r2, r3;
    Free free1;

    randomize();
    
    // Assign each space randomly
    array[randA] = monster1;
    array[randB] = monster2;
    array[randC] = monster3;
    array[randD] = pizza1;
    array[randE] = deliv1;
    array[randF] = r1;
    array[randG] = r2;
    array[randH] = r3;
    array[randI] = free1;
    
    
    

    
    for(int i = 0; i < 9; i++){
        array[i].setPosition(i);
    }

    
    /*
     for(int row = 0; row < NUM_ROWS; row++){
        for(int column = 0; column < NUM_COLS; column++){
            array[row][column] = 'X';
        }
    }
     */
    
}

void Board::print(){
    
    /*
    for(int row = 0; row < NUM_ROWS; row++){
        for(int column = 0; column < NUM_COLS; column++){
            cout << array[row][column];
        }
        cout << endl;
    }
    
    */
    
    for(int i = 0; i < 3; i++){
        std::cout << array[i].getIdentity() << " ";
    }
    std::cout << std::endl;
    for(int i = 3; i < 6; i++){
        std::cout << array[i].getIdentity() << " ";
    }
    std::cout << std::endl;
    for(int i = 6; i < 9; i++){
        std::cout << array[i].getIdentity() << " ";
    }
    std::cout << std::endl << std::endl;
    
    for(int i = 0; i < 3; i++){
        std::cout << array[i].getPosition() << " ";
    }
    std::cout << std::endl;
    for(int i = 3; i < 6; i++){
        std::cout << array[i].getPosition() << " ";
    }
    std::cout << std::endl;
    for(int i = 6; i < 9; i++){
        std::cout << array[i].getPosition() << " ";
    }
    std::cout << std::endl;
    
    
    
    std::cout << std::endl << std::endl << randA << " " << randB << " " << randC << " " << randD << " " << randE << " " << randF << " " << randG << " " << randH << " " << randI << std::endl;
}

// This function assigns the numbers 0-8 randomly to each "randX" member variable.
void Board::randomize(){
    srand (time(NULL)); // seeds for random integers
    
    randA = rand() % 9;
    
    do{
        randB = rand() % 9;
    }while(randB == randA);
    
    do{
        randC = rand() % 9;
    }while(randC == randA || randC == randB);
    
    do{
        randD = rand() % 9;
    }while(randD == randA || randD == randB || randD == randC);
    
    do{
        randE = rand() % 9;
    }while(randE == randA || randE == randB || randE == randC || randE == randD);
    
    do{
        randF = rand() % 9;
    }while(randF == randA || randF == randB || randF == randC || randF == randD || randF == randE);
    
    do{
        randG = rand() % 9;
    }while(randG == randA || randG == randB || randG == randC || randG == randD || randG == randE || randG == randF);
    
    do{
        randH = rand() % 9;
    }while(randH == randA || randH == randB || randH == randC || randH == randD || randH == randE || randH == randF || randH == randG);
    
    do{
        randI = rand() % 9;
    }while(randI == randA || randI == randB || randI == randC || randI == randD || randI == randE || randI == randF || randI == randG || randI == randH);
}

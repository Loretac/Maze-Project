/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
 
 *********************************************************************/

#include "Board.hpp"

using std::cout;
using std::endl;

Board::Board(){
    monster1 = new Monster;
    monster2 = new Monster;
    monster3 = new Monster;
    pizza1 = new Pizza;
    deliv1 = new Delivery;
    r1 = new Random;
    r2 = new Random;
    r3 = new Random;
    free1 = new Free;

    // Randomize the 9 Board member variables to 0-8
    // randomize();
    
    resetBoard(-1);
    
    
    /*
     
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
    
    */
    
    // set the pointers to each array element
    // setPointers();
    
    /*

    // Set the position member variable for each space to its current value
    for(int i = 0; i < 9; i++){
        array[i]->setPosition(i);
        array[i]->setUnoccupied();
        array[i]->setActive(true);
    }
    
    // initialize the starting space to occupied and inactive
    array[randI]->setOccupied();
    array[randI]->setActive(false);
    
    
    
    currentSpace = array[randI];
    
    
    */
}

void Board::setPointers(){
    // Set each of the space pointers
    array[0]->setTopNull();
    array[0]->setLeftNull();
    array[0]->setRight(array[1]);
    array[0]->setBottom(array[3]);
    
    array[1]->setTopNull();
    array[1]->setLeft(array[0]);
    array[1]->setRight(array[2]);
    array[1]->setBottom(array[4]);
    
    array[2]->setTopNull();
    array[2]->setLeft(array[1]);
    array[2]->setRightNull();
    array[2]->setBottom(array[5]);
    
    array[3]->setTop(array[0]);
    array[3]->setLeftNull();
    array[3]->setRight(array[4]);
    array[3]->setBottom(array[6]);
    
    array[4]->setTop(array[1]);
    array[4]->setLeft(array[3]);
    array[4]->setRight(array[5]);
    array[4]->setBottom(array[7]);
    
    array[5]->setTop(array[2]);
    array[5]->setLeft(array[4]);
    array[5]->setRightNull();
    array[5]->setBottom(array[8]);
    
    array[6]->setTop(array[3]);
    array[6]->setLeftNull();
    array[6]->setRight(array[7]);
    array[6]->setBottomNull();
    
    array[7]->setTop(array[4]);
    array[7]->setLeft(array[6]);
    array[7]->setRight(array[8]);
    array[7]->setBottomNull();
    
    array[8]->setTop(array[5]);
    array[8]->setLeft(array[7]);
    array[8]->setRightNull();
    array[8]->setBottomNull();
}

// Prints the board in its current state
void Board::print(){
    
    
    
    for(int i = 0; i < 3; i++){
        if(array[i]->getOccupied() == true){
            std::cout << "O" << " ";
        }
        else if(array[i]->getActive() == false){
            std::cout << " " << " ";
        }
        else{
            std::cout << array[i]->getIdentity() << " ";
        }
    }
    std::cout << std::endl;
    for(int i = 3; i < 6; i++){
        if(array[i]->getOccupied() == true){
            std::cout << "O" << " ";
        }
        else if(array[i]->getActive() == false){
            std::cout << " " << " ";
        }
        else{
            std::cout << array[i]->getIdentity() << " ";
        }
    }
    std::cout << std::endl;
    for(int i = 6; i < 9; i++){
        if(array[i]->getOccupied() == true){
            std::cout << "O" << " ";
        }
        else if(array[i]->getActive() == false){
            std::cout << " " << " ";
        }
        else{
            std::cout << array[i]->getIdentity() << " ";
        }
    }
    std::cout << std::endl << std::endl;
    
    
    /*********************************************************************
     FOR TESTING PURPOSES
     ********************************************************************/
    std::cout << "Occupied:" << std::endl;
    for(int i = 0; i < 3; i++){
        
        std::cout << array[i]->getOccupied() << " ";
    }
    std::cout << std::endl;
    for(int i = 3; i < 6; i++){
        std::cout << array[i]->getOccupied() << " ";
    }
    std::cout << std::endl;
    for(int i = 6; i < 9; i++){
        std::cout << array[i]->getOccupied() << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    
    
    std::cout << "Active:" << std::endl;
    for(int i = 0; i < 3; i++){
        
        std::cout << array[i]->getActive() << " ";
    }
    std::cout << std::endl;
    for(int i = 3; i < 6; i++){
        std::cout << array[i]->getActive() << " ";
    }
    std::cout << std::endl;
    for(int i = 6; i < 9; i++){
        std::cout << array[i]->getActive() << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    
    /*
    
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
    */
    
    
   /* std::cout << std::endl << std::endl << randA << " " << randB << " " << randC << " " << randD << " " << randE << " " << randF << " " << randG << " " << randH << " " << randI << std::endl;
    
    */
}


Space* Board::getCurrent(){
    return currentSpace;
}

void Board::setCurrent(Space* current){
    currentSpace = current;
}


/*********************************************************************
This function assigns the numbers 0-8 randomly to each "randX" member variable.
 ********************************************************************/
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

void Board::resetBoard(int endingPosition){
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
    
    
    // Set the position member variable for each space to its current value
    for(int i = 0; i < 9; i++){
        array[i]->setPosition(i);
        array[i]->setUnoccupied();
        array[i]->setActive(true);
    }
    
    Space* newStartingSpace;
    
    if(endingPosition != -1){ // -1 is only the beginning of the game
        
        
        // run through all the newly randomized spaces to determine which should be the free space
        for(int i = 0; i < 9; i++){
            if(array[i]->getPosition() == endingPosition){
                newStartingSpace = array[i];
                break;
            }
            
        }
        
        // swap
        array[randI] = newStartingSpace;
        array[endingPosition] = free1;
        
        setPointers();
        
        array[endingPosition]->setOccupied();
        array[endingPosition]->setActive(false);
        
        currentSpace = array[endingPosition];
    }
    else{
        // set the pointers to each array element
        setPointers();
        
        
        
        
        // initialize the starting space to occupied and inactive
        array[randI]->setOccupied();
        array[randI]->setActive(false);
        
        
        
        currentSpace = array[randI];
        
    }
}

Board::~Board(){
    for(int i = 0; i < 9; i++){
        delete array[i];
    }
}

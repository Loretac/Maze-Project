/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Random class inherits from the Space class. There are 3 random
 spaces out of the 9 total in the game. Upon entering the space, the
 player encounters a "random event", either gaining spirit points,
 finding a crate with items, or nothing. This file contains the
 function definitions.
 *********************************************************************/

#include "Random.hpp"

/*********************************************************************
 Default constructor
 *********************************************************************/
Random::Random(){
    setIdentity('R');
}

/*********************************************************************
 There is no precondition, thus the function returns 1.
 *********************************************************************/
int Random::precondition(int){
    return 1;
}

/*********************************************************************
 The function returns 3 if the space hasn't been landed on yet. This
 return value is processed by the postconditions function in Game.cpp.
 *********************************************************************/
int Random::postcondition(){
    if(getActive() == true){
        return 3;
    }
    else{
        return 0;
    }
    
}

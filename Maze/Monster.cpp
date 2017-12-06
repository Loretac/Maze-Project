/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Monster class inherits from Space class. The Monster space can
 be entered by a player, but only if they agree to fight the monster,
 which can deal damage towards the player's health. This file contains
 the function definitions for class Monster.
 *********************************************************************/

#include "Monster.hpp"

/*********************************************************************
Default constructor
 *********************************************************************/
Monster::Monster(){
    setIdentity('M');
}

/*********************************************************************
 Precondition function for Monster. If the Monster has been discovered
 but not killed (meaning it is still active) then the function returns
 a 3. Else, it returns a 1. The preConditions function in Game.cpp
 processes these return values.
 *********************************************************************/
int Monster::precondition(int){
    setDiscovered(true);
    if(getActive() == true){
        return 3;
    }
    else{
        return 1;
    }
}

/*********************************************************************
 The Monster class has no postcondition, thus returns 0.
 *********************************************************************/
int Monster::postcondition(){
    return 0;
}

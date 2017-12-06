/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Pizza class inherits from Space class. This space contains the
 pizza, which is the most important item to complete the objective.
 Landing on the pizza space provides a pizza in the player's
 inventory. This file contains the function definitions.
 *********************************************************************/

#include "Pizza.hpp"

/*********************************************************************
 Default constructor
 *********************************************************************/
Pizza::Pizza(){
    setIdentity('P');
}

/*********************************************************************
 Pizza has no precondition, and thus returns 1.
 *********************************************************************/
int Pizza::precondition(int){
    return 1;
}

/*********************************************************************
 The postcondition function returns either 1 or 0 to the postcondition
 function in Game.cpp. 1 = Pizza added to player's inventory, while
 0 = pizza has already been taken.
 *********************************************************************/
int Pizza::postcondition(){
    if(getActive() == true){
        return 1;
    }
    else{
        return 0;
    }
}

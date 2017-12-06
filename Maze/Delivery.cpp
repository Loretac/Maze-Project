/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:

 The Delivery class inherits from Space class. The Delivery space is
 where the player must bring the pizza after finding it. It cannot be
 entered without the pizza. This file contains the function definitions.
 *********************************************************************/

#include "Delivery.hpp"

/*********************************************************************
 Default constructor
 *********************************************************************/
Delivery::Delivery(){
    setIdentity('D');
}

/*********************************************************************
 Precondition function for Delivery returns values that are processed
 by the preCondition function in Game.cpp. A value of 2 is returned
 when the player does not have the pizza, and is thus unable to enter
 the space.
 *********************************************************************/
int Delivery::precondition(int status){
    if(status == 0 || status == 3){
        return 2;
    }
    else{
        return 1;
    }

}

/*********************************************************************
 The postcondition function returns a 2, which is processed by
 Game.cpp. Returning 2 signifies the end of the level.
 *********************************************************************/
int Delivery::postcondition(){
    return 2;
}

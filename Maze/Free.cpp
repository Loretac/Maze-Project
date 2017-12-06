/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Free class inherits from Space class. It's a "free" space where
 nothing happens. This space is always the starting point for each
 level. Each destination, or Delivery space, of a given level becomes
 the Free space of the next level. (The space objects themselves are
 different, but their positions merge.) This file contains the
 function definitions.
 *********************************************************************/

#include "Free.hpp"

/*********************************************************************
 Default constructor
 *********************************************************************/
Free::Free(){
    setIdentity('F');
}

/*********************************************************************
 There is no precondition. Thus, the function returns the default 1.
 *********************************************************************/
int Free::precondition(int){
    return 1;
}

/*********************************************************************
 There is no postcondition. Thus, the function returns the default 0.
 *********************************************************************/
int Free::postcondition(){
    return 0;
}

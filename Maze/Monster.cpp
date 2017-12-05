//
//  Monster.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Monster.hpp"

Monster::Monster(){
    setIdentity('M');
}

int Monster::precondition(int){
    setDiscovered(true);
    if(getActive() == true){
        return 3;
    }
    else{
        return 1;
    }
}

int Monster::postcondition(){
    // placeholder
    return 0;
}

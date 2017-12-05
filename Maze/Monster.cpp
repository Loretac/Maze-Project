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
    return 3;
}

int Monster::postcondition(){
    // placeholder
    return 0;
}

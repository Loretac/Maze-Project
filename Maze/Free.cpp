//
//  Free.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Free.hpp"

Free::Free(){
    setIdentity('F');
}

bool Free::precondition(int){
    return true;
}

int Free::postcondition(){
    // placeholder
    return 0;
}

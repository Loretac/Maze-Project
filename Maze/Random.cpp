//
//  Random.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Random.hpp"

Random::Random(){
    setIdentity('R');
}

bool Random::precondition(int){
    return true;
}

int Random::postcondition(){
    if(getActive() == true){
        return 3;
    }
    else{
        return 0;
    }
    
}

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

int Random::precondition(int){
    return 1;
}

int Random::postcondition(){
    if(getActive() == true){
        return 3;
    }
    else{
        return 0;
    }
    
}

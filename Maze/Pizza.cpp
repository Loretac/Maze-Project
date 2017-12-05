//
//  Pizza.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Pizza.hpp"

Pizza::Pizza(){
    setIdentity('P');
}

int Pizza::precondition(int){
    return 1;
}

int Pizza::postcondition(){
    if(getActive() == true){
        return 1;
    }
    else{
        return 0;
    }
}

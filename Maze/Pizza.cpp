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

bool Pizza::precondition(){
    return true;
}

int Pizza::postcondition(){
    if(getActive() == true){
        std::cout << "You found the pizza!" << std::endl;
    }
    return 1;
}

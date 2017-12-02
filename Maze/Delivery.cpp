//
//  Delivery.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Delivery.hpp"

Delivery::Delivery(){
    setIdentity('D');
}

bool Delivery::precondition(int status){
    if(status == 0 || status == 3){
        std::cout << "You probably shouldn't go to the house without having the pizza first." << std::endl;
        return false;
    }
    else{
        return true;
    }

}

int Delivery::postcondition(){
    // placeholder
    return 0;
}

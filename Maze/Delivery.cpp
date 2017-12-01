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

bool Delivery::precondition(){
    std::cout << "You probably shouldn't go to the house without having the pizza first." << std::endl;
    return false;
}

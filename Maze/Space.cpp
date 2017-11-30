//
//  Space.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Space.hpp"

void Space::setPosition(int i){
    position = i;
}

int Space::getPosition(){
    return position;
}

void Space::setIdentity(char id){
    identity = id;
}

char Space::getIdentity(){
    return identity;
}

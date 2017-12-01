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

void Space::setOccupied(){
    isOccupied = true;
}

void Space::setUnoccupied(){
    isOccupied = false;
}

bool Space::getOccupied(){
    return isOccupied;
}

Space* Space::getTop(){
    return top;
}

Space* Space::getRight(){
    return right;
}

Space* Space::getLeft(){
    return left;
}

Space* Space::getBottom(){
    return bottom;
}

void Space::setTop(Space* topSpace){
    top = topSpace;
}

void Space::setRight(Space* rightSpace){
    right = rightSpace;
}

void Space::setLeft(Space* leftSpace){
    left = leftSpace;
}

void Space::setBottom(Space* bottomSpace){
    bottom = bottomSpace;
}

void Space::setTopNull(){
    top = nullptr;
}

void Space::setRightNull(){
    right = nullptr;
}

void Space::setLeftNull(){
    left = nullptr;
}

void Space::setBottomNull(){
    bottom = nullptr;
}

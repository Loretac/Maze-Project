/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Space class is a virtual class. The Monster, Pizza, Delivery,
 Random, and Free classes inherit from Space. This file contains the
 function definitions (primarily getters and setters).
 *********************************************************************/

#include "Space.hpp"

void Space::setPosition(int i){
    position = i;
}

bool Space::getActive(){
    return isActive;
}

void Space::setActive(bool active){
    isActive = active;
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

bool Space::getDiscovered(){
    return isDiscovered;
}

void Space::setDiscovered(bool i){
    isDiscovered = i;
}

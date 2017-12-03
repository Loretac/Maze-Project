//
//  Player.cpp
//  Maze
//
//  Created by Chris Loreta on 12/1/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    health = 100;
    spirit = 100;
    garlic = 0;
    pizza = false; // player does not start out with pizza
    delivery = false; // delivery signifies the completion of the level
}

bool Player::getPizza(){
    return pizza;
}

void Player::setPizza(bool ifPizza){
    pizza = ifPizza;
}

int Player::getGarlic(){
    return garlic;
}

void Player::setGarlic(int i){
    garlic = i;
}

int Player::getHealth(){
    return health;
}

void Player::setHealth(int i){
    health = i;
}

bool Player::getDelivery(){
    return delivery;
}

void Player::setDelivery(bool i){
    delivery = i;
}

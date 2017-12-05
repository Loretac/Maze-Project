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
    whiskey = 0;
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

int Player::getWhiskey(){
    return whiskey;
}

void Player::setWhiskey(int i){
    whiskey = i;
}

int Player::getHealth(){
    return health;
}

void Player::setHealth(int i){
    health = i;
}

int Player::getSpirit(){
    return spirit;
}

void Player::setSpirit(int i){
    spirit = i;
}

bool Player::getDelivery(){
    return delivery;
}

void Player::setDelivery(bool i){
    delivery = i;
}

void Player::printInventory(){
    std::cout << "Has pizza: ";
    if(getPizza() == true){
        std::cout << "yes";
    }
    else{
        std::cout << "no";
    }
    std::cout << std::endl;
    
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Spirit: " << getSpirit() << std::endl;
    
    std::cout << "Whiskey: " << getWhiskey() << std::endl;
    std::cout << "Garlic: " << getGarlic() << std::endl;
}

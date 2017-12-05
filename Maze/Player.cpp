//
//  Player.cpp
//  Maze
//
//  Created by Chris Loreta on 12/1/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Player.hpp"

using std::string;
using std::setw;

Player::Player(){
    level = 0;
    health = 85;
    spirit = 85;
    garlic = 0;
    whiskey = 0;
    pizza = false; // player does not start out with pizza
    delivery = false; // delivery signifies the completion of the level
}

int Player::getLevel(){
    return level;
}

void Player::setLevel(int i){
    level = i;
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

    std::cout << std::endl;
    
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Spirit: " << getSpirit() << std::endl;
    
    std::cout << "Whiskey: " << getWhiskey() << std::endl;
    std::cout << "Garlic: " << getGarlic() << std::endl;
    

    string isPizza;
    if(getPizza() == false){
        isPizza = "-";
    }
    else{
        isPizza = "YES";
    }
    
    string whiskeyString = std::to_string(getWhiskey());
    string garlicString = std::to_string(getGarlic());
    
    string items = " Items: ";
    if(whiskey > 0){
        items += "Whiskey";
        items += "(";
        items += whiskeyString;
        items += ")";
    }
    if(garlic > 0 && whiskey > 0){
        items += ", ";
    }
    if(garlic > 0){
        items += "Garlic";
        items += "(";
        items += garlicString;
        items += ")";
        
    }

    const int width = 19;
    const int levelWidth = 6;
    const int pizzaWidth = 7;
    
    const int columns = 4;
    const string sep = " |";
    const int totalWidth = width * 2 + levelWidth + pizzaWidth + sep.size() * columns;
    const string line = " |" + string(totalWidth-1, '-') + '|';
    
    
    string healthBar;
    string spiritBar;
    
    if(health == 0){
        healthBar = " ";
    }
    else{
        healthBar = string((health) / 5 + 1, '=');
    }
    
    if(spirit == 0){
        spiritBar = " ";
    }
    else{
        spiritBar = string((spirit) / 5 + 1, '=');
    }
    
    
    
    
    
    std::cout << line << '\n' << sep
    << setw(levelWidth) << "Level" << sep << setw(pizzaWidth) << "Pizza?" << sep << setw(width)
    << "Health      " << sep << setw(width) << "Spirit      " << sep << '\n' << line << '\n';
    
    std::cout << sep << setw(levelWidth) << level << sep << setw(pizzaWidth) << isPizza << sep << setw(width)
    << healthBar << sep << setw(width) << spiritBar << sep << '\n' ;
    
    std::cout << line << '\n';
    
    
    std::cout << sep << setw(57) << std::left << items << std::right << sep << '\n';
    
    std::cout << line << '\n' << '\n';
}

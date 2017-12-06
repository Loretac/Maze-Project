/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Player class contains all items that relate to the player and
 their related functions. Things like health, spirit level, items in
 inventory, and current level are all part of the class. This file
 contains the function definitions.
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include "Player.hpp"

using std::string;
using std::setw;

/*********************************************************************
 Default constructor
 *********************************************************************/
Player::Player(){
    level = 0;
    health = 85;
    spirit = 85;
    garlic = 0;
    whiskey = 0;
    pizza = false; // player does not start out with pizza
    delivery = false; // delivery signifies the completion of the level
    garlicPizza = false;
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

void Player::setGarlicPizza(bool i){
    garlicPizza = i;
}

bool Player::getGarlicPizza(){
    return garlicPizza;
}

/*********************************************************************
 This function prints the player's inventory at the top of the
 interface, shown during the entire game.
 *********************************************************************/
void Player::printInventory(){

    string isPizza;
    if(getPizza() == false){
        isPizza = "-";
    }
    else if(getGarlicPizza() == true){
        isPizza = "YES(G)"; // Garlic pizza
    }
    else{
        isPizza = "YES";
    }
    
    // For converting ints to strings
    string whiskeyString = std::to_string(getWhiskey());
    string garlicString = std::to_string(getGarlic());
    
    // Displays all items in inventory
    string items = " Press u to use items: ";
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

    // Custom column widths for table
    const int width = 19;
    const int levelWidth = 6;
    const int pizzaWidth = 7;
    
    const int columns = 4;
    const string separator = " |";
    const string border = "|";
    const int totalWidth = width * 2 + levelWidth + pizzaWidth +
        separator.size() * columns;
    const string line = border + string(totalWidth-1, '-') + '|';
    
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
    
    std::cout << line << '\n';
    
    std::cout << border << setw(57) << std::left
    << " ----------------- PIZZA DELIVERY GAME ------------------"
    << std::right << separator << '\n';
    
    std::cout << border << setw(57) << std::left << ""
    << std::right << separator << '\n';
    
    std::cout << border << setw(57) << std::left
    << " Movement: e,s,d,f keys                  Press i for help"
    << std::right << separator << '\n';
    
    std::cout << line << '\n';
    
    
    std::cout << border << setw(levelWidth) << "Level" << separator
    << setw(pizzaWidth) << "Pizza?" << separator << setw(width)
    << "Health      " << separator << setw(width) << "Spirit      "
    << separator << '\n';

    
    std::cout << border << setw(levelWidth) << level << separator
    << setw(pizzaWidth) << isPizza << separator << setw(width)
    << healthBar << separator << setw(width) << spiritBar
    << separator << '\n' ;
    
    std::cout << line << '\n';
    
    
    std::cout << border << setw(57) << std::left << items << std::right
    << separator << '\n';
    
    std::cout << line << '\n';
}

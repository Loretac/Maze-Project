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
    pizza = false;
}

bool Player::getPizza(){
    return pizza;
}

void Player::setPizza(bool ifPizza){
    pizza = ifPizza;
}

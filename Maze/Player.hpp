//
//  Player.hpp
//  Maze
//
//  Created by Chris Loreta on 12/1/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Board.hpp"

class Player
{
private:
    int health;
    int spirit;
    int garlic;
    bool pizza;
    
public:
    Player();
    bool getPizza();
    void setPizza(bool);
    int getHealth();
    void setHealth(int);
    int getGarlic();
    void setGarlic(int);
    
};

#endif /* Player_hpp */

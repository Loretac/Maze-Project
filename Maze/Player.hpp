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
    int whiskey;
    bool pizza;
    bool delivery;
    
public:
    Player();
    bool getPizza();
    void setPizza(bool);
    int getHealth();
    void setHealth(int);
    int getSpirit();
    void setSpirit(int);
    int getGarlic();
    void setGarlic(int);
    int getWhiskey();
    void setWhiskey(int);
    bool getDelivery();
    void setDelivery(bool);
    void printInventory();
    
};

#endif /* Player_hpp */

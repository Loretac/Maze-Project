//
//  Game.hpp
//  Maze
//
//  Created by Chris Loreta on 11/22/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Player.hpp"

class Game
{
private:
    Board myboard;
    Player myplayer;
    int status; // codes feed into space/s precondition function
    
public:
    // Game();
    void play();
    void makeMove();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void updateStatus();
    
};

#endif /* Game_hpp */

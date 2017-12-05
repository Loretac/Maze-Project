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
#include "TextQueue.hpp"

class Game
{
private:
    Board myboard;
    Player myplayer;
    int status; // codes feed into space/s precondition function
    int numLevel;
    Queue chatbox;
    
public:
    // Game();
    void play();
    void makeMove();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void updateStatus();
    void playLevel();
    int preConditions(int);
    void postConditions(int);
    void printAll();
    
    
};

#endif /* Game_hpp */

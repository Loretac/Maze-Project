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
#include "Board.hpp"

class Game
{
private:
    Board myboard;
    
public:
    // Game();
    void play();
    void makeMove();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    
};

#endif /* Game_hpp */

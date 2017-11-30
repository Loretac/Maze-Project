//
//  Game.cpp
//  Maze
//
//  Created by Chris Loreta on 11/22/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

using std::string;

void Game::play(){
    makeMove();
}

void Game::makeMove(){
    string input;
    for(int i = 0; i < 100; i++){
        // std::cout << "Type something: ";
        myboard.print();
        getline(std::cin, input);
    }
    
}

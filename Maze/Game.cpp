//
//  Game.cpp
//  Maze
//
//  Created by Chris Loreta on 11/22/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Game.hpp"

using std::string;

void Game::makeMove(){
    string input;
    for(int i = 0; i < 100; i++){
        std::cout << "Type something: ";
        getline(std::cin, input);
        myboard.print();
    }
    
}

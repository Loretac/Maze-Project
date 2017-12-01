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
    for(int i = 0; i < 100; i++){
        makeMove();
    }
    
}

void Game::makeMove(){
    string input;
    
        myboard.print();
    std::cout << "Type something: " << std::endl;
        getline(std::cin, input);
    
    
    while(input != "e" && input != "s" && input != "d" && input != "f"){
        std::cout << "Please try again." << std::endl;
        getline(std::cin, input);
    }
    if(input == "e"){
        moveUp();
    }
    if(input == "d"){
        moveDown();
    }
    if(input == "s"){
        moveLeft();
    }
    if(input == "f"){
        moveRight();
    }
    
    
}

void Game::moveUp(){
    if(myboard.getCurrent()->getTop() == nullptr){
        std::cout << "You cannot move up." << std::endl;
    }
    else{
        myboard.getCurrent()->getTop()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        myboard.setCurrent(myboard.getCurrent()->getTop());
    }

}

void Game::moveDown(){
    if(myboard.getCurrent()->getBottom() == nullptr){
        std::cout << "You cannot move down." << std::endl;
    }
    else{
        myboard.getCurrent()->getBottom()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        myboard.setCurrent(myboard.getCurrent()->getBottom());
    }
}

void Game::moveLeft(){
    if(myboard.getCurrent()->getLeft() == nullptr){
        std::cout << "You cannot move left." << std::endl;
    }
    else{
        myboard.getCurrent()->getLeft()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        myboard.setCurrent(myboard.getCurrent()->getLeft());
    }
}

void Game::moveRight(){
    if(myboard.getCurrent()->getRight() == nullptr){
        std::cout << "You cannot move right." << std::endl;
    }
    else{
        myboard.getCurrent()->getRight()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        myboard.setCurrent(myboard.getCurrent()->getRight());
    }
}

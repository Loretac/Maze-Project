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
    status = 0; // initialize status to 0
    numLevel = 0;
    
    while(1){
        numLevel++;
        myplayer.setDelivery(false); // player does not start out with delivery
        myplayer.setPizza(false); // player does not start out with pizza
        updateStatus();
        
        playLevel(); // loop levels until player dies
        if(myplayer.getHealth() == 0){
            break;
        }
    }
}

void Game::playLevel(){
    // loop moves until player dies or level is complete
    while(1){
        std::cout << "Level " << numLevel << std::endl;
        makeMove();
        
        if(myplayer.getHealth() == 0){
            std::cout << "You died!" << std::endl;
            break;
        }
        else if(myplayer.getDelivery() == true){
            myplayer.printInventory();
            myboard.print();
            std::cout << "Press Enter to move on to the next level..." << std::endl;
            std::cin.ignore();
            
            // set up the board for the next round. the only space that stays the same is the ending delivery space, which turns into the free space.
            int endingSpace = myboard.getCurrent()->getPosition();
            
            myboard.resetBoard(endingSpace);
            break;
        }
    }
    
    
    
}

void Game::makeMove(){
    string input; // letter input determines direction of movement
    
    myplayer.printInventory();
    
    
    std::cout << std::endl;
    
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
    if(myboard.getCurrent()->getTop() == nullptr || myboard.getCurrent()->getTop() == NULL){
        std::cout << "You cannot move up." << std::endl;
    }
    else if(myboard.getCurrent()->getTop()->precondition(status) == true){
        myboard.getCurrent()->getTop()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition before setting new space to inactive
        int postValue = myboard.getCurrent()->getTop()->postcondition();
        
        postConditions(postValue);
        

        
        myboard.setCurrent(myboard.getCurrent()->getTop());
        
        myboard.getCurrent()->setActive(false);
        
        updateStatus();
    }

}

void Game::moveDown(){
    if(myboard.getCurrent()->getBottom() == nullptr || myboard.getCurrent()->getBottom() == NULL){
        std::cout << "You cannot move down." << std::endl;
    }
    else if(myboard.getCurrent()->getBottom()->precondition(status) == true){
        myboard.getCurrent()->getBottom()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition
        int postValue = myboard.getCurrent()->getBottom()->postcondition();
        
        postConditions(postValue);
        

        myboard.setCurrent(myboard.getCurrent()->getBottom());
        myboard.getCurrent()->setActive(false);
        
        updateStatus();
    }
}

void Game::moveLeft(){
    if(myboard.getCurrent()->getLeft() == nullptr || myboard.getCurrent()->getLeft() == NULL){
        std::cout << "You cannot move left." << std::endl;
    }
    else if(myboard.getCurrent()->getLeft()->precondition(status) == true){
        myboard.getCurrent()->getLeft()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition
        int postValue = myboard.getCurrent()->getLeft()->postcondition();
        
        postConditions(postValue);
        

        myboard.setCurrent(myboard.getCurrent()->getLeft());
        myboard.getCurrent()->setActive(false);
        
        updateStatus();
    }
}

void Game::moveRight(){
    
    
    
    if(myboard.getCurrent()->getRight() == nullptr || myboard.getCurrent()->getRight() == NULL){
        std::cout << "You cannot move right." << std::endl;
    }
    else if(myboard.getCurrent()->getRight()->precondition(status) == true){
        myboard.getCurrent()->getRight()->setOccupied();
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition
        int postValue = myboard.getCurrent()->getRight()->postcondition();
        
        postConditions(postValue);
        
        
        myboard.setCurrent(myboard.getCurrent()->getRight());
        myboard.getCurrent()->setActive(false);
        
        updateStatus();
        
    }
}

void Game::updateStatus(){
    if(myplayer.getPizza() == false && myplayer.getGarlic() == false){
        status = 0;
    }
    if(myplayer.getPizza() == true && myplayer.getGarlic() == false){
        status = 1;
    }
    if(myplayer.getPizza() == true && myplayer.getGarlic() == true){
        status = 2;
    }
    if(myplayer.getPizza() == false && myplayer.getGarlic() == true){
        status = 3;
    }
}

void Game::postConditions(int value){
    if(value == 1){
        myplayer.setPizza(true);
    }
    if(value == 2){
        myplayer.setDelivery(true);
    }
    if(value == 3){
        int randomEvent = rand() % 2;
        if(randomEvent == 0){
            // gain spirit points
            int spiritGain = rand() % 10 + 1;
            
            // If this increase puts them over 100, cap at 100 max.
            if(myplayer.getSpirit() == 100){
                std::cout << "You take a rest. At least there are no monsters here!" << std::endl;
            }
            else if(myplayer.getSpirit() + spiritGain > 100){
                std::cout << "You found " << 100 - myplayer.getSpirit() << " spirit points!" << std::endl;
                myplayer.setSpirit(100);
            }
            else{
                std::cout << "You found " << spiritGain << " spirit points!" << std::endl;
                myplayer.setSpirit(myplayer.getSpirit() + spiritGain);
            }

        }
        if(randomEvent == 1){
            string input;
            std::cout << "You found a crate." << std::endl;
            std::cout << "1. Open crate" << std::endl;
            std::cout << "2. Destroy crate" << std::endl;
            
            getline(std::cin, input);
            
            while(input != "1" && input != "2"){
                std::cout << "Please try again." << std::endl;
                getline(std::cin, input);
            }
            if(input == "1"){
                //find garlic or whiskey
                int randomCrate = rand() % 2;
                
                if(randomCrate == 0){
                    std::cout << "You search the crate and find some garlic." << std::endl;
                    myplayer.setGarlic(myplayer.getGarlic() + 1);
                }
                if(randomCrate == 1){
                    std::cout << "You search the crate and find some whiskey." << std::endl;
                    myplayer.setWhiskey(myplayer.getWhiskey() + 1);
                }
            }
            if(input == "2"){
                // destroy the crate, i.e. do nothing
                std::cout << "You destroy the crate." << std::endl;
            }
            
        }

    }
}

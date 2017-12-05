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
        
        makeMove();
        
        if(myplayer.getHealth() == 0){
            chatbox.addToQueue("You died!");
            chatbox.addToQueue("Press 1 to play again.");
            chatbox.addToQueue("Or press any button to quit.");
            printAll();
            
            break;
        }
        else if(myplayer.getDelivery() == true){
            
            printAll();
            
            // myplayer.printInventory();
            // myboard.print();
            // std::cout << "Press Enter to move on to the next level..." << std::endl;
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
    
    printAll();
        getline(std::cin, input);
    
    int i = 0;
    while(input != "e" && input != "s" && input != "d" && input != "f"){
        if(i == 0){
            chatbox.addToQueue("Please try again.");
            i++;
        }
        
        
        printAll();
        
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
        chatbox.addToQueue("You cannot move up.");
    }
    else if(preConditions(myboard.getCurrent()->getTop()->precondition(status)) == 1){
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
        chatbox.addToQueue("You cannot move down.");
    }
    else if(preConditions(myboard.getCurrent()->getBottom()->precondition(status))  == 1){
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
        chatbox.addToQueue("You cannot move left.");
    }
    else if(preConditions(myboard.getCurrent()->getLeft()->precondition(status))  == 1){
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
        chatbox.addToQueue("You cannot move right.");
    }
    else if(preConditions(myboard.getCurrent()->getRight()->precondition(status))  == 1){
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
    if(myplayer.getPizza() == false && myplayer.getGarlic() == 0){
        status = 0;
    }
    if(myplayer.getPizza() == true && myplayer.getGarlic() == 0){
        status = 1;
    }
    if(myplayer.getPizza() == true && myplayer.getGarlic() > 0){
        status = 2;
    }
    if(myplayer.getPizza() == false && myplayer.getGarlic() > 0){
        status = 3;
    }
}

int Game::preConditions(int value){
    if(value == 1){
        return 1;
    }
    if(value == 2){
        chatbox.addToQueue("You probably shouldn't go to the house without having the pizza first.");
        return 2;
    }
    // monster
    if(value == 3){
        string input;
        int i = 0;
        chatbox.addToQueue("You encounter a monster!");
        chatbox.addToQueue("1. Fight the monster");
        chatbox.addToQueue("2. Leave");
        
        printAll();
        
        getline(std::cin, input);
        
        while(input != "1" && input != "2"){
            if(i == 0){
                chatbox.addToQueue("Please try again.");
                i++;

            }
            printAll();
            getline(std::cin, input);
        }
        
        if(input == "1"){
            //fight
            chatbox.addToQueue("You took damage!");
            myplayer.setHealth(myplayer.getHealth() - 50);
            return 1;
        }
        if(input == "2"){
            chatbox.addToQueue("You return to your previous space.");
            return 0;
        }
        
        return 1;
    }
    else{
        return 0;
    }
}

void Game::postConditions(int value){
    if(value == 1){
        chatbox.addToQueue("You found the pizza!");
        myplayer.setPizza(true);
    }
    if(value == 2){
        chatbox.addToQueue("Mission accomplished. You delivered the pizza!");
        chatbox.addToQueue("Press Enter to move on to the next level...");
        myplayer.setDelivery(true);
    }
    if(value == 3){
        int randomEvent = rand() % 2;
        if(randomEvent == 0){
            // gain spirit points
            int spiritGain = rand() % 10 + 1;
            
            // If this increase puts them over 100, cap at 100 max.
            if(myplayer.getSpirit() == 100){
                chatbox.addToQueue("You take a rest. At least there are no monsters here!");
            }
            else if(myplayer.getSpirit() + spiritGain > 100){
                chatbox.addToQueue("You found spirit points!");
                myplayer.setSpirit(100);
            }
            else{
                chatbox.addToQueue("You found spirit points!");
                myplayer.setSpirit(myplayer.getSpirit() + spiritGain);
            }

        }
        if(randomEvent == 1){
            string input;
            chatbox.addToQueue("You found a crate.");
            chatbox.addToQueue("1. Open crate");
            chatbox.addToQueue("2. Destroy crate");
            
            
            
            printAll();

            getline(std::cin, input);
            
            
            int i = 0;
            while(input != "1" && input != "2"){
                
                // this message only shows in the chatbox once.
                if(i == 0){
                    chatbox.addToQueue("Please try again.");
                }
                printAll();
   
                getline(std::cin, input);
                i++;
            }
            if(input == "1"){
                //find garlic or whiskey
                int randomCrate = rand() % 2;
                
                if(randomCrate == 0){
                    chatbox.addToQueue("You search the crate and find some garlic.");
                    myplayer.setGarlic(myplayer.getGarlic() + 1);
                }
                if(randomCrate == 1){
                    chatbox.addToQueue("You search the crate and find some whiskey.");
                    myplayer.setWhiskey(myplayer.getWhiskey() + 1);
                }
            }
            if(input == "2"){
                // destroy the crate, i.e. do nothing
                chatbox.addToQueue("You destroy the crate.");
            }
            
        }

    }
}

void Game::printAll(){
    
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "Level " << numLevel << std::endl;
    myplayer.printInventory();
    myboard.print();
    chatbox.printQueue();
    
    std::cout << "Type something:" << std::endl;
}

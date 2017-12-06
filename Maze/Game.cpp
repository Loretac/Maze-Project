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
    
    while(1){
        myplayer.setLevel(myplayer.getLevel() + 1);
        myplayer.setDelivery(false); // player does not start out with delivery
        myplayer.setPizza(false); // player does not start out with pizza
        myplayer.setGarlicPizza(false);
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
            chatbox.addToQueue("Press 1 to return to the menu.");
            chatbox.addToQueue("Or press 2 to quit.");
            printAll();
            
            break;
        }
        else if(myplayer.getDelivery() == true){
            
            printAll();
            
            std::string choice;
            int k = 0;
            
            getline(std::cin, choice);
            while(choice != "1" && choice != "2"){
                if(k == 0){
                    chatbox.addToQueue("Please try again.");
                    k++;
                }
                
                printAll();
                getline(std::cin, choice);
                
            }

            if(choice == "2"){
                store();
            }
            
            chatbox.addToQueue("Moving to next level...");
            
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
    while(input != "e" &&
          input != "s" &&
          input != "d" &&
          input != "f" &&
          input != "i" &&
          input != "u"){
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
    if(input == "u"){
        useItems();
    }
    if(input == "i"){
        tutorial(1);
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
        chatbox.addToQueue("You need the pizza first before going to the house.");
        return 2;
    }
    // monster
    if(value == 3){
        string input;
        int i = 0;
        chatbox.addToQueue("You encounter a monster!");
        chatbox.addToQueue("1. Go fight the monster");
        chatbox.addToQueue("2. Stay where you are");
        
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
            
            int damage = 20 + ((rand() % (myplayer.getLevel() + 20)) * 2);
            //fight
            chatbox.addToQueue("You killed the monster! You took some damage.");
            
            if(myplayer.getHealth() - damage < 0){
                myplayer.setHealth(0);
            }
            else{
                myplayer.setHealth(myplayer.getHealth() - damage);
            }
            
            
            return 1;
        }
        if(input == "2"){
            chatbox.addToQueue("You stay in your current space.");
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
        chatbox.addToQueue("**** Level complete! ****");
        
        if(myplayer.getGarlicPizza() == true){
            chatbox.addToQueue("The customer loved the garlic pizza!");
            chatbox.addToQueue("You are awarded extra spirit points.");
            if(myplayer.getSpirit() + 30 > 85){
                myplayer.setSpirit(85);
            }
            else{
                myplayer.setSpirit(myplayer.getSpirit() + 30);
            }
        }
        else{
            chatbox.addToQueue("You delivered the pizza!");
        }
        chatbox.addToQueue("1. Move on to next level");
        chatbox.addToQueue("2. Shop at store");
        myplayer.setDelivery(true);
    }
    if(value == 3){
        int randomEvent = rand() % 2;
        if(randomEvent == 0){
            // gain spirit points
            int spiritGain = rand() % 10 + 1;
            
            // If this increase puts them over 100, cap at 100 max.
            if(myplayer.getSpirit() == 85){
                chatbox.addToQueue("You take a rest. At least there are no monsters here!");
            }
            else if(myplayer.getSpirit() + spiritGain > 85){
                chatbox.addToQueue("You found spirit points!");
                myplayer.setSpirit(85);
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
                int randomCrate = rand() % 3;
                
                if(randomCrate == 0 && myplayer.getGarlic()  < 3){
                    chatbox.addToQueue("You search the crate and find some garlic.");
                    myplayer.setGarlic(myplayer.getGarlic() + 1);
                }
                else if(randomCrate == 0){
                    chatbox.addToQueue("There is nothing in the crate.");
                }
                if(randomCrate == 1 && myplayer.getWhiskey() < 10){
                    chatbox.addToQueue("You search the crate and find some whiskey.");
                    myplayer.setWhiskey(myplayer.getWhiskey() + 1);
                }
                else if(randomCrate == 1){
                    chatbox.addToQueue("There is nothing in the crate.");
                }
                if(randomCrate == 2){
                    chatbox.addToQueue("There is nothing in the crate.");
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
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    myplayer.printInventory();
    myboard.print();
    chatbox.printQueue();
    
    std::cout << "Type something: ";
}

void Game::store(){
    
    chatbox.addToQueue("Entering store...");
    
    while(1){
        chatbox.addToQueue("1. Buy whiskey");
        chatbox.addToQueue("2. Continue to next level");
        
        printAll();
        
        std::string choice;
        int k = 0;
        
        getline(std::cin, choice);
        while(choice != "1" && choice != "2"){
            if(k == 0){
                chatbox.addToQueue("Please try again.");
                k++;
            }
            
            printAll();
            getline(std::cin, choice);
            
        }
        if(choice == "1"){
            if(myplayer.getWhiskey() > 9){
                chatbox.addToQueue("You have enough whiskey.");
            }
            else if(myplayer.getSpirit() < 30){
                chatbox.addToQueue("You don't have enough spirit points.");
            }
            else{
                chatbox.addToQueue(" ");
                chatbox.addToQueue("You bought 1 whiskey.");
                myplayer.setSpirit(myplayer.getSpirit()  - 30);
                myplayer.setWhiskey(myplayer.getWhiskey() + 1);
            }
            
        }
        if(choice == "2"){
            break;
        }
    }
    

    

    

}

void Game::useItems(){
    if(myplayer.getWhiskey() == 0 && myplayer.getGarlic() == 0){
        chatbox.addToQueue("You have no items to use.");
    }
    else if(myplayer.getWhiskey() > 0 && myplayer.getGarlic() == 0){
        chatbox.addToQueue("1. Drink whiskey");
        chatbox.addToQueue("2. Cancel");
        
        std::string i;
        int k = 0;
        
        printAll();
        
        getline(std::cin, i);
        while(i != "1" && i != "2"){
            if(k == 0){
                chatbox.addToQueue("Please try again.");
                k++;
            }
            
            printAll();
            getline(std::cin, i);
            
        }
        if(i == "1"){
            drinkWhiskey();
        }
        if(i == "2"){
            chatbox.addToQueue("Cancelling.");
        }
    }
    else if(myplayer.getWhiskey() > 0 && myplayer.getGarlic() > 0){
        chatbox.addToQueue("1. Drink whiskey");
        chatbox.addToQueue("2. Use garlic on pizza");
        chatbox.addToQueue("3. Cancel");
        
        std::string i;
        int k = 0;
        
        printAll();
        
        getline(std::cin, i);
        while(i != "1" && i != "2" && i != "3"){
            if(k == 0){
                chatbox.addToQueue("Please try again.");
                k++;
            }
            
            printAll();
            getline(std::cin, i);
            
        }
        if(i == "1"){
            drinkWhiskey();
        }
        if(i == "2"){
            useGarlic();
        }
        if(i == "3"){
            chatbox.addToQueue("Cancelling.");
        }
    }
    else if(myplayer.getWhiskey() == 0 && myplayer.getGarlic() > 0){
        chatbox.addToQueue("1. Use garlic on pizza");
        chatbox.addToQueue("2. Cancel");
        
        std::string i;
        int k = 0;
        
        printAll();
        
        getline(std::cin, i);
        while(i != "1" && i != "2"){
            if(k == 0){
                chatbox.addToQueue("Please try again.");
                k++;
            }
            
            printAll();
            getline(std::cin, i);
            
        }
        if(i == "1"){
            useGarlic();
        }
        if(i == "2"){
            chatbox.addToQueue("Cancelling.");
        }
    }
}

void Game::drinkWhiskey(){
    myplayer.setWhiskey(myplayer.getWhiskey() - 1);
    
    if(myplayer.getHealth() + 20 > 85){
        myplayer.setHealth(85);
    }
    else{
        myplayer.setHealth(myplayer.getHealth() + 20);
    }
    chatbox.addToQueue("You drink whiskey to heal some health.");
}

void Game::useGarlic(){
    if(myplayer.getPizza() == false){
        chatbox.addToQueue("You should get the pizza first.");
    }
    else if(myplayer.getGarlicPizza() == true){
        chatbox.addToQueue("The pizza already has garlic on it.");
    }
    else{
        myplayer.setGarlicPizza(true);
        myplayer.setGarlic(myplayer.getGarlic() - 1);
        chatbox.addToQueue("You add the garlic to the pizza.");
    }
}

void Game::tutorial(int i){
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    
    
    
    
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| ----------------- PIZZA DELIVERY GAME ------------------ |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                         TUTORIAL                         |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| Level | Pizza? |       Health       |       Spirit       |" << std::endl;
    std::cout << "|       |        |                    |                    |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    if(i == 0){
        std::cout << "|            Press Enter to return to menu.                |" << std::endl;
    }
    if(i == 1){
        std::cout << "|            Press Enter to return to game.                |" << std::endl;
    }
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                         e     Move up                    |" << std::endl;
    std::cout << "|                         d     Move down                  |" << std::endl;
    std::cout << "|           Controls:     s     Move left                  |" << std::endl;
    std::cout << "|                         f     Move right                 |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "| XXXXXXXXXXXXXXXXXXXX                                     |" << std::endl;
    std::cout << "| XXXXXXXXXXXXXXXXXXXX                                     |" << std::endl;
    std::cout << "| XXXXXXXXXXXXXXXXXXXX <----        This is you.           |" << std::endl;
    std::cout << "| XXXXXXXXXXXXXXXXXXXX                                     |" << std::endl;
    std::cout << "| XXXXXXXXXXXXXXXXXXXX                                     |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "| ====================                                     |" << std::endl;
    std::cout << "| ====================            Find the pizza.          |" << std::endl;
    std::cout << "| ==================== <----    Deliver it to the home.    |" << std::endl;
    std::cout << "| ====================                                     |" << std::endl;
    std::cout << "| ====================                                     |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "| !!!!!!!!!!!!!!!!!!!!                                     |" << std::endl;
    std::cout << "| !!!!!!!!!!!!!!!!!!!!                                     |" << std::endl;
    std::cout << "| !!!!!!!!!!!!!!!!!!!! <- Avoid getting killed by monsters.|" << std::endl;
    std::cout << "| !!!!!!!!!!!!!!!!!!!!                                     |" << std::endl;
    std::cout << "| !!!!!!!!!!!!!!!!!!!!                                     |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    At the end of each level, you can buy items with      |" << std::endl;
    std::cout << "|    spirit points.                                        |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    Don't let your health get to zero!                    |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cin.ignore();
}

void Game::menu(int i){
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    
    
    
    
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| ----------------- PIZZA DELIVERY GAME ------------------ |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| Level | Pizza? |       Health       |       Spirit       |" << std::endl;
    std::cout << "|       |        |                    |                    |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    1. Play                                               |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    2. How to play                                        |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    3. Quit                                               |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    if(i == 0){
        std::cout << "|                                                          |" << std::endl;
    }
    if(i == 1){
        std::cout << "|             Please choose a valid option.                |" << std::endl;
    }
    
    std::cout << "|                                                          |" << std::endl;

}

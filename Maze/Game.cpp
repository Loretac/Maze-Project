/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Game class contains all the primary operations of the game. This
 file contains the function definitions.
 *********************************************************************/

#include <iostream>
#include "Game.hpp"

using std::string;

/*********************************************************************
 The entire game runs through the play function.
 *********************************************************************/
void Game::play(){
    status = 0; // initialize status to 0
    
    while(1){
        myplayer.setLevel(myplayer.getLevel() + 1);
        
        // player does not start out with delivery
        myplayer.setDelivery(false);
        
        // player does not start out with pizza
        myplayer.setPizza(false);
        myplayer.setGarlicPizza(false);
        updateStatus();
        
        playLevel(); // loop levels until player dies
        if(myplayer.getHealth() == 0){
            break;
        }
    }
}

/*********************************************************************
 This function loops moves until the player dies or completes the
 level.
 *********************************************************************/
void Game::playLevel(){
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
            
            // Counter so message only shows once
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
            
            // set up the board for the next round. the only space
            // that stays the same is the ending delivery space,
            // which turns into the free space.
            int endingSpace = myboard.getCurrent()->getPosition();
            
            myboard.resetBoard(endingSpace);
            break;
        }
    }
}

/*********************************************************************
 This function runs every move the player makes.
 *********************************************************************/
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
        // Try again for valid input
        
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

/*********************************************************************
 This function runs if the player enters 'e', and moves the player
 up if they are able to.
 *********************************************************************/
void Game::moveUp(){
    // Cannot move up further
    if(myboard.getCurrent()->getTop() == nullptr ||
       myboard.getCurrent()->getTop() == NULL){
        chatbox.addToQueue("You cannot move up.");
    }
    // preconditions will only return 1 if player allowed to proceed
    else if(preConditions(myboard.getCurrent()->getTop()->precondition(status)) == 1){
        
        // space above now occupied
        myboard.getCurrent()->getTop()->setOccupied();
        
        // current space now unoccupied
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition before setting new space to inactive
        int postValue = myboard.getCurrent()->getTop()->postcondition();
        
        postConditions(postValue);
        
        // update current space
        myboard.setCurrent(myboard.getCurrent()->getTop());
        
        // set new current space to inactive
        myboard.getCurrent()->setActive(false);
        
        // update the player's inventory status
        updateStatus();
    }

}

/*********************************************************************
 This function runs if the player enters 'd', and moves the player
 down if they are able to.
 *********************************************************************/
void Game::moveDown(){
    // Cannot move down further
    if(myboard.getCurrent()->getBottom() == nullptr ||
       myboard.getCurrent()->getBottom() == NULL){
        chatbox.addToQueue("You cannot move down.");
    }
    // preconditions will only return 1 if player allowed to proceed
    else if(preConditions(myboard.getCurrent()->getBottom()->precondition(status))  == 1){
        
        // space below now occupied
        myboard.getCurrent()->getBottom()->setOccupied();
        
        // current space now unoccupied
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition before setting new space to inactive
        int postValue = myboard.getCurrent()->getBottom()->postcondition();
        
        postConditions(postValue);
        
        // update current space
        myboard.setCurrent(myboard.getCurrent()->getBottom());
        
        // set new current space to inactive
        myboard.getCurrent()->setActive(false);
        
        // update the player's inventory status
        updateStatus();
    }
}

/*********************************************************************
 This function runs if the player enters 'd', and moves the player
 down if they are able to.
 *********************************************************************/
void Game::moveLeft(){
    // Cannot move left any further
    if(myboard.getCurrent()->getLeft() == nullptr ||
       myboard.getCurrent()->getLeft() == NULL){
        chatbox.addToQueue("You cannot move left.");
    }
    // preconditions will only return 1 if player allowed to proceed
    else if(preConditions(myboard.getCurrent()->getLeft()->precondition(status))  == 1){
        
        // space to the left now occupied
        myboard.getCurrent()->getLeft()->setOccupied();
        
        // current space now unoccupied
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition before setting new space to inactice
        int postValue = myboard.getCurrent()->getLeft()->postcondition();
        
        postConditions(postValue);
        
        // update current space
        myboard.setCurrent(myboard.getCurrent()->getLeft());
        
        // set old space to inactive
        myboard.getCurrent()->setActive(false);
        
        // update the player's inventory status
        updateStatus();
    }
}

/*********************************************************************
 This function runs if the player enters 'd', and moves the player
 down if they are able to.
 *********************************************************************/
void Game::moveRight(){
    // Cannot move right any further
    if(myboard.getCurrent()->getRight() == nullptr ||
       myboard.getCurrent()->getRight() == NULL){
        chatbox.addToQueue("You cannot move right.");
    }
    // preconditions will only return 1 if player allowed to proceed
    else if(preConditions(myboard.getCurrent()->getRight()->precondition(status))  == 1){
        
        // space to the right now occupied
        myboard.getCurrent()->getRight()->setOccupied();
        
        // current space now unoccupied
        myboard.getCurrent()->setUnoccupied();
        
        // run postcondition before setting new space to inactive
        int postValue = myboard.getCurrent()->getRight()->postcondition();
        
        postConditions(postValue);
        
        // update current space
        myboard.setCurrent(myboard.getCurrent()->getRight());
        
        // set new current space to inactive
        myboard.getCurrent()->setActive(false);
        
        // update the player's inventory status
        updateStatus();
        
    }
}

/*********************************************************************
 This function updates the player's "status". The statuses are as
 follows:
 0 - No pizza and no garlic
 1 - Pizza and no garlic
 2 - Pizza and garlic
 3 - No pizza and garlic
 
 These codes are fed into Spaces' precondition functions, which is
 then passed again to the preCondition function below to determine
 if the player is allowed to proceed into the space. For example, a
 0 or 3 status means the player does not have the pizza, so the
 Delivery precondition function would deny the player access to the
 space.
 *********************************************************************/
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

/*********************************************************************
 The preconditions function takes as a parameter the value returned
 from a space's precondition function. The reason this function
 processes the actual consequences of the preconditions as opposed to
 the Spaces' precondition functions themselves is because those
 functions don't have access to the Player's member variables.
 Returning a 1 means the player is allowed to proceed.
 *********************************************************************/
int Game::preConditions(int value){
    if(value == 1){
        return 1; // allowed to proceed
    }
    if(value == 2){
        chatbox.addToQueue("You need the pizza first before going to the house.");
        return 2; // rejected
    }
    // Monster space
    if(value == 3){
        // 50/50 chance werewolf or vampire
        int monsterType = rand() % 2;
        int i = 0;
        string input;
        if(monsterType == 0){
            chatbox.addToQueue("You encounter a werewolf!");
            chatbox.addToQueue("1. Go fight the werewolf");
            chatbox.addToQueue("2. Stay where you are");
        }
        if(monsterType == 1 && myplayer.getGarlic() == 0){
            chatbox.addToQueue("You encounter a vampire!");
            chatbox.addToQueue("1. Go fight the vampire");
            chatbox.addToQueue("2. Stay where you are");
        }
        if(monsterType == 0 || myplayer.getGarlic() == 0){
            printAll();
            getline(std::cin, input);
            
            while(input != "1" && input != "2"){
                if(i == 0){ // message appears max 1 time
                    chatbox.addToQueue("Please try again.");
                    i++;
                }
                printAll();
                getline(std::cin, input);
            }
            
            if(input == "1"){
                // Standard damage function that increases with level
                int damage = 20 + ((rand() % (myplayer.getLevel()
                                              + 20)) * 2);
                // fight the monster
                chatbox.addToQueue("You killed the monster! You took some damage.");
                
                // health can't be negative
                if(myplayer.getHealth() - damage < 0){
                    myplayer.setHealth(0);
                }
                else{
                    myplayer.setHealth(myplayer.getHealth() - damage);
                }
                return 1; // monster killed, so allowed to proceed
            }
            if(input == "2"){
                chatbox.addToQueue("You stay in your current space.");
                return 0; // not allowed to proceed
            }
        }
        // if the monster is a vampire and the player has garlic,
        // the player is given an extra option
        if(monsterType == 1 && myplayer.getGarlic() > 0){
            chatbox.addToQueue("You encounter a vampire!");
            chatbox.addToQueue("1. Go fight the vampire");
            chatbox.addToQueue("2. Stay where you are");
            chatbox.addToQueue("3. Fight vampire using garlic");
            
            printAll();
            getline(std::cin, input);
            
            while(input != "1" && input != "2" && input != "3"){
                if(i == 0){ // message appears max 1 time
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
                return 1; //  vampire killed; allowed to proceed
            }
            if(input == "2"){
                chatbox.addToQueue("You stay in your current space.");
                return 0; // not allowed to proceed
            }
            if(input == "3"){
                // damage function significantly lesser
                int damage = ((rand() % (myplayer.getLevel() + 20)));
                
                // fight the vampire
                chatbox.addToQueue("You use your garlic fighting the vampire and come away");
                chatbox.addToQueue("mostly unscathed!");
                myplayer.setGarlic(myplayer.getGarlic() - 1);
                
                if(myplayer.getHealth() - damage < 0){
                    myplayer.setHealth(0);
                }
                else{
                    myplayer.setHealth(myplayer.getHealth() - damage);
                }
            }
        return 1; // prevent errors from if statements
    }
    else{
        return 1; // prevent errors from if statements
    }
}
    
    return 1; // prevent errors from if statements
}

/*********************************************************************
 The preconditions function takes as a parameter the value returned
 from a space's precondition function. The existence of this function
 is similar to preConditions function above. However, this function
 returns no values. The integer parameter is passed from the space's
 postcondition functions.
 *********************************************************************/
void Game::postConditions(int value){
    if(value == 1){ // When the pizza is found
        
        chatbox.addToQueue("You found the pizza!");
        myplayer.setPizza(true);
    }
    if(value == 2){ // When the pizza is delivered
        chatbox.addToQueue("**** Level complete! ****");
        
        // If the player added garlic to the pizza
        if(myplayer.getGarlicPizza() == true){
            chatbox.addToQueue("The customer loved the garlic pizza!");
            chatbox.addToQueue("You are awarded extra spirit points.");
            
            // spirit cannot be over 85
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
    if(value == 3){ // When player lands on random event space
        // 50/50 chance spirit point gain or crate
        int randomEvent = rand() % 2;
        if(randomEvent == 0){
            // gain spirit points
            int spiritGain = rand() % 10 + 1;
            
            if(myplayer.getSpirit() == 85){
                chatbox.addToQueue("You take a rest. At least there are no monsters here!");
            }
            // If this increase puts them over 85, cap at 85 max.
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
                // find garlic, whiskey, or nothing
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

/*********************************************************************
 The printAll function combines multiple print functions into one
 and not only prints every move but often multiple times per move.
 The interface refreshes every time the user inputs anything, even
 if it is incorrect input. Thus, the printAll function is very
 frequently used.
 *********************************************************************/
void Game::printAll(){
    
    // These extra spaces are to push the old content out of the
    // console window.
    std::cout << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl;
    myplayer.printInventory();
    myboard.print();
    chatbox.printQueue();
    
    std::cout << "Type something: ";
}

/*********************************************************************
 The store function can only be run at the end of a level. It allows
 the player to purchase whiskey (more items can be added).
 *********************************************************************/
void Game::store(){
    
    chatbox.addToQueue("Entering store...");
    
    while(1){ // loops until player chooses to leave
        chatbox.addToQueue("1. Buy whiskey");
        chatbox.addToQueue("2. Continue to next level");
        
        printAll();
        
        std::string choice;
        int k = 0;
        
        getline(std::cin, choice);
        while(choice != "1" && choice != "2"){
            if(k == 0){ // message appears max 1 time
                chatbox.addToQueue("Please try again.");
                k++;
            }
            
            printAll();
            getline(std::cin, choice);
            
        }
        if(choice == "1"){
            if(myplayer.getWhiskey() > 9){ // max 10 whiskey
                chatbox.addToQueue("You have enough whiskey.");
            }
            else if(myplayer.getSpirit() < 30){ // costs 30 spirit pts
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

/*********************************************************************
 This function is called whenever the user enters 'u', and is more of
 a menu function to determine which item will be used. The functions
 involving the actual drinking of whiskey and use of garlic are later.
 *********************************************************************/
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
            if(k == 0){ // message shows max 1 time
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

/*********************************************************************
 This function runs when the player elects to drink a whiskey in
 the item usage menu.
 *********************************************************************/
void Game::drinkWhiskey(){
    // decrease whiskey count by 1
    myplayer.setWhiskey(myplayer.getWhiskey() - 1);
    
    // health cannot be over 85. whiskey adds 20
    if(myplayer.getHealth() + 20 > 85){
        myplayer.setHealth(85);
    }
    else{
        myplayer.setHealth(myplayer.getHealth() + 20);
    }
    chatbox.addToQueue("You drink whiskey to heal some health.");
}

/*********************************************************************
 This function runs when the player elects to use garlic in
 the item usage menu. They must already have the pizza.
 *********************************************************************/
void Game::useGarlic(){
    if(myplayer.getPizza() == false){
        chatbox.addToQueue("You should get the pizza first.");
    }
    else if(myplayer.getGarlicPizza() == true){
        chatbox.addToQueue("The pizza already has garlic on it.");
    }
    else{
        // the GarlicPizza variable determines if the pizza has garlic.
        myplayer.setGarlicPizza(true);
        
        // decrease player's garlic count by 1
        myplayer.setGarlic(myplayer.getGarlic() - 1);
        chatbox.addToQueue("You add the garlic to the pizza.");
    }
}

/*********************************************************************
 This function prints out a tutorial screen and can be accessed by
 pressing 'i' during a level or via the main menu.
 *********************************************************************/
void Game::tutorial(int i){
    std::cout << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl;
    
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

/*********************************************************************
 This menu function appears at the beginning of the game and after
 the end of a game if a player wishes to return to it.
 *********************************************************************/
void Game::menu(int i){
    std::cout << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl
    << std::endl << std::endl << std::endl << std::endl << std::endl;
    
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| ----------------- PIZZA DELIVERY GAME ------------------ |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "| Level | Pizza? |       Health       |       Spirit       |" << std::endl;
    std::cout << "|       |        |                    |                    |" << std::endl;
    std::cout << "|----------------------------------------------------------|" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|    Note: Please resize screen to fit this window.        |" << std::endl;
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

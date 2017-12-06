/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 The Pizza Delivery game sets the player as a pizza delivery officer.
 Their goal is to find the pizza in a maze of spaces, and deliver it
 to its destination without being killed by monsters. The player
 can lose health to monseters, but can also gain items or spend
 spirit points to buy items at the end of levels. These items can
 help fight the monsters or restore health.
 *********************************************************************/

#include <iostream>
#include "Game.hpp"

using std::string;

int main(int argc, const char * argv[]) {
   
    
    while(1){
        string input;
        Game newGame;
        
        newGame.menu(0);
        getline(std::cin, input);
        
        while(input != "1" &&
              input != "2" &&
              input != "3"){
            
            newGame.menu(1);
            getline(std::cin, input);
        }
        
        if(input == "1"){
            string choice;
            newGame.play();
            getline(std::cin, choice);
            
            
            
        }
        else if(input == "2"){
            newGame.tutorial(0);
        }
        else if(input == "3"){
            break;
        }
    }
    
    

    
    
    return 0;
}

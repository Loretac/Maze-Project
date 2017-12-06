/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
 
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

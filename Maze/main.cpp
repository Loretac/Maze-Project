/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 22 Nov 2017
 ** Description:
 
 
 *********************************************************************/

#include <iostream>
#include "Game.hpp"

using std::string;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    string input;
    
    Game newGame;
    newGame.play();
    
    getline(std::cin, input);
    
    while(input == "1"){
        Game nextGame;
        nextGame.play();
        getline(std::cin, input);
    }
    
    
    return 0;
}

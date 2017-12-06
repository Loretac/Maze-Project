/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This function contains all the member variables and function
 prototypes of the class Game.
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "TextQueue.hpp"

class Game
{
private:
    Board myboard;
    Player myplayer;
    int status; // codes feed into space/s precondition function
    Queue chatbox;
    
public:
    // Game();
    void play();
    void makeMove();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void updateStatus();
    void playLevel();
    int preConditions(int);
    void postConditions(int);
    void printAll();
    void store();
    void useItems();
    void drinkWhiskey();
    void useGarlic();
    void tutorial(int);
    void menu(int);
    
    
};

#endif /* Game_hpp */

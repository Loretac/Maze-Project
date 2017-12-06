/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the function prototypes for class Monster.
 *********************************************************************/

#ifndef Monster_hpp
#define Monster_hpp

#include <iostream>
#include "Space.hpp"

class Monster : public Space // Inherits from Space class
{
private:
    
public:
    Monster(); // Default constructor
    virtual int precondition(int);
    virtual int postcondition();
};

#endif /* Monster_hpp */

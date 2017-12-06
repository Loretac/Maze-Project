/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the function prototypes for class Pizza.
 *********************************************************************/

#ifndef Pizza_hpp
#define Pizza_hpp

#include <iostream>
#include "Monster.hpp"

class Pizza : public Space
{
private:
    
public:
    Pizza();
    virtual int precondition(int);
    virtual int postcondition();
};

#endif /* Pizza_hpp */

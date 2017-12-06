/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the function prototypes for class Random.
 *********************************************************************/

#ifndef Random_hpp
#define Random_hpp

#include <stdio.h>
#include "Delivery.hpp"

class Random : public Space
{
private:
    
public:
    Random();
    virtual int precondition(int);
    virtual int postcondition();
};

#endif /* Random_hpp */

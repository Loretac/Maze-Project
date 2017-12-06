/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the function prototypes for class Delivery.
 *********************************************************************/

#ifndef Delivery_hpp
#define Delivery_hpp

#include <iostream>
#include "Pizza.hpp"

class Delivery : public Space
{
private:
    
public:
    Delivery();
    virtual int precondition(int);
    virtual int postcondition();
};

#endif /* Delivery_hpp */

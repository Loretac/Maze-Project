//
//  Delivery.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Delivery_hpp
#define Delivery_hpp

#include <iostream>
#include "Pizza.hpp"

class Delivery : public Space
{
private:
    
public:
    Delivery();
    virtual bool precondition(int);
    virtual int postcondition();
};

#endif /* Delivery_hpp */

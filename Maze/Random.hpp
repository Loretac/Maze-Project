//
//  Random.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

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

//
//  Monster.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Monster_hpp
#define Monster_hpp

#include <iostream>
#include "Space.hpp"

class Monster : public Space // Inherits from Space class
{
private:
    
public:
    Monster();
    virtual bool precondition(int);
    virtual int postcondition();
};

#endif /* Monster_hpp */

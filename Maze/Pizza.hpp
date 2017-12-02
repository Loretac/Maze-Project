//
//  Pizza.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Pizza_hpp
#define Pizza_hpp

#include <iostream>
#include "Monster.hpp"

class Pizza : public Space
{
private:
    
public:
    Pizza();
    virtual bool precondition();
    virtual int postcondition();
};

#endif /* Pizza_hpp */

//
//  Free.hpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#ifndef Free_hpp
#define Free_hpp

#include <stdio.h>
#include "Random.hpp"

class Free : public Space
{
private:
    
public:
    Free();
    virtual int precondition(int);
    virtual int postcondition();
};

#endif /* Free_hpp */

/*********************************************************************
 ** Author: Chris Loreta
 ** Date: 05 Dec 2017
 ** Description:
 
 This file contains the function prototypes for class Free.
 *********************************************************************/

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

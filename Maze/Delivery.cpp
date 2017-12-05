//
//  Delivery.cpp
//  Maze
//
//  Created by Chris Loreta on 11/29/17.
//  Copyright © 2017 Chris Loreta. All rights reserved.
//

#include "Delivery.hpp"

Delivery::Delivery(){
    setIdentity('D');
}

int Delivery::precondition(int status){
    if(status == 0 || status == 3){
        return 2;
    }
    else{
        return 1;
    }

}

int Delivery::postcondition(){
    return 2;
}

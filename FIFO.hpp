//
//  FIFO.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef FIFO_hpp
#define FIFO_hpp

#include <stdio.h>
#include "PRA.hpp"
#include <queue>
#include <list>

/*
[3]->[2]->[1]
*/

/*
 fixed size array with a varible called first 
 [7][5][6]   
*/

/*
[5]-[3]->[?]
*/


class FIFO: public PRA{
public:
    FIFO();
    ~FIFO();
    
private:
    
};

#endif /* FIFO_hpp */

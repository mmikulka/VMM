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

struct queue_lim{
    queue<Frames> queue_struct;
    
    void add_node(Frame passed_f) {
        if(queue_struct.size() < 16) {
            queue_struct.push(passed_f);
        } else { // this means the queue is larger than 17
            cout << "the maximum size of the queue has been reached\n";
        }
    }
    
};

class FIFO: public PRA{
public:
    FIFO();
    ~FIFO();
    
private:
    queue_lim local_queue;
};

#endif /* FIFO_hpp */

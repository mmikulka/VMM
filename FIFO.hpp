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

class FIFO: public PRA{
public:
    FIFO();
    unsigned select_frame(int type);
    void update_usage(uint32_t);
    ~FIFO();
private:
    static std::list<uint32_t> replacement_ram;
    static std::list<uint32_t> replacement_tlb;
};

#endif /* FIFO_hpp */

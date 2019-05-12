//
//  LRU.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef LRU_hpp
#define LRU_hpp

#include <stdio.h>
#include "PRA.hpp"

class LRU : public PRA {
public:
    LRU();
    unsigned select_frame(int type);
    void increment_frame(int framenum);
    void remove_frame();
    ~LRU();
    
private:
    static std::list<uint32_t> replacement_ram;
    static std::list<uint32_t> replacement_tlb;
    static std::list<int>      replacement_ram_counters;
};

#endif /* LRU_hpp */

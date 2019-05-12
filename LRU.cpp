//
//  LRU.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "LRU.hpp"

LRU::LRU() {
    for (int i = 0; i < 128; ++i)
    {
        replacement_ram.push_back(i);
        replacement_ram_counters.push_back(0);
    }
    for (int i = 0; i < 16; ++i)
    {
        replacement_tlb.push_back(i);
    }
}

unsigned LRU::select_frame(int type) {
    /*
        i think that we should have a counter attached to each of the
            pages that records how many times it was accessed and then
            constantly be grabbing the page with the smallest value
     */
}

LRU::~LRU(){
    
}

std::list<uint32_t> LRU::replacement_ram;
std::list<uint32_t> LRU::replacement_tlb;
std::list<int>      LRU::replacement_ram_counters;

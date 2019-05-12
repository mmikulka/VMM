//
//  FIFO.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "FIFO.hpp"


FIFO::FIFO() {
    for (int i = 0; i < 128; ++i)
    {
        replacement_ram.push_back(i);
    }
    for (int i = 0; i < 16; ++i)
    {
        replacement_tlb.push_back(i);
    }
}

unsigned FIFO::select_frame(int type) //1 for TLB; 0 for RAM
{
    Word frame;
    if (type == 0)
    {
        frame.value_ = replacement_ram.front();
        replacement_ram.pop_front();
        replacement_ram.push_back(frame.value_);

    }
    else
    {
        frame.value_ = replacement_tlb.front();
        replacement_tlb.pop_front();
        replacement_tlb.push_back(frame.value_);
    }
    return frame.value_;
}

FIFO::~FIFO(){

}
std::list<uint32_t> FIFO::replacement_ram;
std::list<uint32_t> FIFO::replacement_tlb;

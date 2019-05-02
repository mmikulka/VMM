//
//  MMU.cpp
//
//

#include "MMU.h"


MMU MMU::instance()
{
    pageAccessCounts_ = 0;
    pageInFaults_ = 0;
    tlbAccessCount_ = 0;
    tlbFaults_ = 0;
    return *this; // dummy return
}

void MMU::clearTLB(){}

int MMU::pageAccesses()
{
    return pageAccessCounts_;
}

int MMU::pageFaults()
{
    return pageInFaults_;
}

int MMU::TLBAccesses()
{
    return tlbAccessCount_;
}

int MMU::TLBFaults()
{
    return tlbFaults_;
}

template <typename T>
void MMU::read(T &addr)
{
    
}

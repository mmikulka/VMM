//
//  MMU.cpp
//
//

#include "MMU.h"


MMU::MMU(){}

MMU::MMU(MMU&){}

MMU MMU::instance()
{
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

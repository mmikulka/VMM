//
//  MMU.cpp
//
//

#include "MMU.h"


/*MMU MMU::instance()
{
    pageAccessCounts_ = 0;
    pageInFaults_ = 0;
    tlbAccessCount_ = 0;
    tlbFaults_ = 0;
    return *this; // dummy return
}*/

MMU::MMU()
{
    pageAccessCounts_ = 0;
    pageInFaults_ = 0;
    tlbAccessCount_ = 0;
    tlbFaults_ = 0;
    tlb_.pageNum.fill(-1);
    tlb_.FrameNum.fill(-1);
}

void MMU::clearTLB()
{
    tlb_.pageNum.fill(-1);
    tlb_.FrameNum.fill(-1);
}

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

void MMU::read(Address &addr) // translate address to info
{
    //get page number from address info
    //see if page is in Page table
    //if not we receive a page fault and  page in from backing store
}

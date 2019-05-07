//
//  MMU.cpp
//
//

#include "MMU.hpp"
#include "PCB.hpp"
#include "RAM.hpp"
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

unsigned MMU::read(Address &addr) // translate address to info
{
  Word pageNum = addr.page();
  unsigned frameNum = PCB::findFrame(pageNum);
  if (frameNum > 255)
    {
         RAM::read(frameNum);
        ++pageAccessCounts_;
    }
    else
    {
        MemoryManager mM;
        mM.pageIn(addr);
        frameNum = PCB::findFrame(pageNum);
        RAM::read(frameNum);
        ++pageInFaults_;
    }
    return frameNum;
}
/*
TODO:

implement TLB 
*/

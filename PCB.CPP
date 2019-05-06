
#include "PCB.h"


PCB::PCB()
{
    
}

Word PCB::addframe(const Word &pageNumber, const Word &frameNum)
{
    return frameNum;
}

unsigned PCB::findFrame(const Word &pageNum)
{
    PageTableEntry temp = pageTable[pageNum.value_];
    if (temp.valid)
    {
        return temp.frameNumber;
    }
    return 500;
}
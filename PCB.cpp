
#include "PCB.hpp"


PCB::PCB()
{

}

void PCB::addFrame(const Word &pageNumber, const unsigned &frameNum)
{
    PageTableEntry entry;
    entry.frameNumber = frameNum;
    entry.valid = true;
    pageTable[pageNumber.value_] = entry;
}

unsigned PCB::findFrame(const Word &pageNum)
{
    PageTableEntry temp = pageTable[pageNum.value_];
    if (temp.valid)
    {
        return temp.frameNumber;
    }
    return 256;
}

std::array <PageTableEntry, 256> PCB::pageTable;

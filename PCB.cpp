
#include "PCB.hpp"


PCB::PCB()
{

}

void PCB::addFrame(const Word &pageNumber, const unsigned &frameNum)
{
    //TBC
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

#ifndef PCB_h
#define PCB_h

#include <array>
#include "Word.hpp"

struct PageTableEntry
{
public:
    unsigned frameNumber;
    bool valid = false;
};

class PCB
{
public:
    PCB();
    Word addframe(const Word &pageNumber, const Word &FrameNumber);
    static unsigned findFrame(const Word &);
private:
    static std::array <PageTableEntry, 256> pageTable;
};

#endif
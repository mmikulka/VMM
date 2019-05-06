//
//  MMU.hpp
//
//
//

#ifndef MMU_h
#define MMU_h

#include <stdio.h>
#include "Word.h"
#include "MemoryManager.h"
#include <array>
#include "PCB.h"

struct TLB
{
    std:: array<int,16> pageNum;
    std::array <int, 16> FrameNum;
};


class MMU
{
public:
    MMU();//=delete;
    //MMU(MMU&); // = delete;
    //MMU instance();
    void clearTLB();
    int pageAccesses();
    int pageFaults();
    int TLBAccesses();
    int TLBFaults();

    void read(Address &addr);

    u_int32_t return_test();

private:
    static int pageAccessCounts_;
    static int pageInFaults_;
    static int tlbAccessCount_;
    static int tlbFaults_;
    static TLB tlb_;

    struct PageFault
    {
        PageFault();
        Word pageNumber_;
    };
};



#endif /* MMU_h */

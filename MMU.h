//
//  MMU.hpp
//  
//
//

#ifndef MMU_hpp
#define MMU_hpp

#include <stdio.h>
#include "Word.h"
#include "MemoryManager.h"
#include <array>

struct TLB
{
    std:: array<int,16> pageNum = {0};
    std::array <int, 16> FrameNum = {0};
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
    int pageAccessCounts_;
    int pageInFaults_;
    int tlbAccessCount_;
    int tlbFaults_;
    TLB tlb_;
    
    struct PageFault
    {
        PageFault();
        Word pageNumber_;
    };
};



#endif /* MMU_hpp */

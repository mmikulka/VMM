//
//  MMU.hpp
//  
//
//

#ifndef MMU_hpp
#define MMU_hpp

#include <stdio.h>
#include "Word.h"

struct TLB
{
    int tlb[16] = {0};
};


class MMU
{
public:
    MMU();
    MMU(MMU&);
    MMU instance();
    void clearTLB();
    int pageAccesses();
    int pageFaults();
    int TLBAccesses();
    int TLBFaults();
    template <typename t>
    void read(t &addr);
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

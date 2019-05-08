//
//  MMU.hpp
//
//
//

#ifndef MMU_h
#define MMU_h

#include <stdio.h>
#include "Word.hpp"
#include "MemoryManager.hpp"
#include <array>
#include "PCB.hpp"

struct TLB
{
	std::array<int, 16> pageNum;
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


	unsigned char read(Address &addr);

	//u_int32_t return_test();

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



#endif /* MMU_h */

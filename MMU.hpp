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

	struct PageFault
	{
		PageFault();
		PageFault(const Word &);
		Word pageNumber_;
	};

	//u_int32_t return_test();

private:
	Word tlb_search(Word& pageNum);

	static int pageAccessCounts_;
	static int pageInFaults_;
	static int tlbAccessCount_;
	static int tlbFaults_;
	static TLB tlb_;
};



#endif /* MMU_h */

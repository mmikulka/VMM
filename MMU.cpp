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

enum PRA_decision{FIFO_, LRU_};

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

unsigned char MMU::read(Address & addr) // translate address to info
{
	Word pageNum = addr.page(); // extract page number from address.
	unsigned char data = 0;
	unsigned frameNum;
	//see if pageNum is in TLB
	frameNum = tlb_search(pageNum);
	if (frameNum > RAM_CHECK_SIZE)
	{
		++tlbFaults_;
		frameNum = PCB::findFrame(pageNum);
	}
	else
	{
		++tlbAccessCount_;
	}

	if (frameNum > RAM_CHECK_SIZE)
		throw PageFault(pageNum);
	else if (frameNum <= RAM_CHECK_SIZE)
	{
		data = RAM::read(frameNum, addr);
		tlb_add(frameNum, pageNum.value_);//need frame number and pagenumber
		++pageAccessCounts_;

	}
	return data;
}

unsigned MMU::tlb_search(Word& pageNum)
{
	for (int i =0; i < TLB_SIZE; ++i)
	{
		if (pageNum.value_ == tlb_.pageNum[i])
		{
			return tlb_.FrameNum[i];
		}
	}
	return 257;
}

void MMU::tlb_add(uint32_t frameNum, uint32_t pageNum) //
{
	uint32_t entry;
	PRA_decision decision = FIFO_;
	PRA *pra;
	if (decision == FIFO_)
	{
		pra = new FIFO();
	}
	else
	{
		//pra = new LRU();
	}
	entry = pra->select_frame(101);
	tlb_.FrameNum[entry] = frameNum;
	tlb_.pageNum[entry] = pageNum;
}

MMU::PageFault::PageFault(const Word & pn)
{
	pageNumber_ = pn;
}

int MMU::pageAccessCounts_ = 0;
int MMU::pageInFaults_ = 0;
int MMU::tlbAccessCount_ = 0;
int MMU::tlbFaults_ = 0;
TLB MMU::tlb_;

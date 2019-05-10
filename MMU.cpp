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
	unsigned char data;
	unsigned frameNum;
	//see if pageNum is in TLB
	//frameNum = tlb_search(pageNum);
	frameNum = PCB::findFrame(pageNum);

	if (frameNum > 255)
		throw PageFault(pageNum);
	if (frameNum <= 255)
	{
		data = RAM::read(frameNum, addr);
		//add value to TLB
		++pageAccessCounts_;
	}
	return data;
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
/*
TODO:

implement TLB
*/

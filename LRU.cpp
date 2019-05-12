//
//  LRU.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "LRU.hpp"
#include "constVars.hpp"

LRU::LRU() {
	for (int i = 0; i < 128; ++i)
	{
		LRU_Stat ram_stat;
		//ram_stat.pageNum = 256;
		time(&ram_stat.timestamp);
		replacement_ram_time_stamps[i] = ram_stat;
	}
	for (int i = 0; i < 16; ++i)
	{
		LRU_Stat tlb_stat;
		//tlb_stat.pageNum = 256;
		time(&tlb_stat.timestamp);
		replacement_tlb_counters[i] = tlb_stat;
	}
}

unsigned LRU::select_frame(int type)
{
	LRU_Stat stat;
	time(&stat.timestamp);
	if (type == 0) //replacement Ram
	{
		for (int i = 0; i < RAM_SIZE; ++i)
		{
			if (replacement_ram_time_stamps[i].timestamp <= stat.timestamp)
			{
				stat = replacement_ram_time_stamps[i];
			}
		}
	}
	else //replacement TLB
	{
		for (int i = 0; i < TLB_SIZE; ++i)
		{
			if (replacement_tlb_counters[i].timestamp <= stat.timestamp)
			{
				stat = replacement_tlb_counters[i];
			}
		}
	}

	return stat.pageNum;
}

void LRU::replace(uint32_t frameNum, uint32_t pageNum, int type)
{
	if (type == 0)// this is for the RAM
	{
		replacement_ram_time_stamps[frameNum].pageNum = pageNum;
		time(&replacement_ram_time_stamps[frameNum].timestamp);
	}
	else // for TLB
	{
		replacement_tlb_counters[frameNum].pageNum = pageNum;
		time(&replacement_tlb_counters[frameNum].timestamp);
	}
}


void LRU::update_usage(uint32_t frameNum, int type)
{
	if (type == 0) // replacement ram 
	{

		LRU_Stat ram_stat;
		//ram_stat.pageNum = 256;
		time(&ram_stat.timestamp);
		replacement_ram_time_stamps[frameNum] = ram_stat;

	}
	else
	{
		LRU_Stat tlb_stat;
		//tlb_stat.pageNum = 256;
		time(&tlb_stat.timestamp);
		replacement_tlb_counters[frameNum] = tlb_stat;
	}
}


LRU::~LRU()
{
	for (int i = 0; i < RAM_SIZE; ++i)
	{
		
	}

}


std::array<LRU_Stat, RAM_SIZE> LRU::replacement_ram_time_stamps;
std::array<LRU_Stat, TLB_SIZE> LRU::replacement_tlb_counters;
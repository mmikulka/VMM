//
//  MemoryManager.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "MemoryManager.hpp"


MemoryManager::MemoryManager()
{
	for (int i = 0; i < 256; ++i)
	{
		freeFrames.push(i);
	}
}

void MemoryManager::pageIn(Address & addr)
{
	Word pageNum = addr.page();
	BackingStore back;
	Word item = back.read(addr);
	unsigned frameNum;
	if (freeFrames.size() > 0)
	{
		frameNum = freeFrames.front();
		freeFrames.pop();
	}
	RAM ram;
	ram.addFrame(item, frameNum);
	PCB::addFrame(pageNum, frameNum);
}

std::queue<unsigned> MemoryManager::freeFrames;

/*
TODO:

Add PRA to pageIn
*/

/*void MemoryManager::read(Address & pageNumber)
{

}*/

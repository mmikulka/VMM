//
//  RAM.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "RAM.hpp"

RAM::RAM()
{

}


unsigned char RAM::read(unsigned frameNum, const Address &addr)
{
	unsigned char data;
	statuses[frameNum].accessed = true;
	data = static_cast<unsigned char>(frames[frameNum].value_);
	return data;
}

void RAM::addFrame(const Word &item, unsigned frameNum)
{
	frames[frameNum] = item;
	statuses[frameNum].accessed = false;
	statuses[frameNum].dirty = false;
}

/*void RAM::deleteFrame(unsigned FrameNum)
{
	frames[FrameNum] = NULL;
}*/

std::array<Word, 256> RAM::frames;
std::array<Status, 256> RAM::statuses;
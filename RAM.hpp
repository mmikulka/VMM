#pragma once
//
//  RAM.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright � 2019 Matthew Mikulka. All rights reserved.
//

#ifndef RAM_hpp
#define RAM_hpp

#include <stdio.h>
#include <array>
#include "Word.hpp"

struct Status
{
	bool accessed = false;
	bool dirty = false;
};

class RAM
{
public:
	RAM();
	static unsigned char read(unsigned frameNum, Address&);
	void addFrame(const Word &Item, unsigned FrameNum);
	//void deleteFrame(unsigned FrameNum);
private:
	static std::array<Word, 256> frames;
	static std::array<Status, 256> statuses;
};

#endif /* RAM_hpp */

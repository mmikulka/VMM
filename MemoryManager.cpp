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

void MemoryManager::pageIn(Word & item)
{
    BackingStore back;
    back.read(item);
    unsigned frameNum;
    if (freeFrames.size() > 0)
    {
        frameNum = freeFrames.front();
        freeFrames.pop();
    }
    RAM ram;
    ram.addFrame(item, frameNum);
}

void MemoryManager::read(Word & pageNumber)
{

}

//
//  RAM.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "RAM.h"

RAM::RAM()
{
    
}


Word RAM::read(unsigned frameNum)
{
    statuses[frameNum].accessed = true;
    return frames[frameNum];
}

void RAM::addFrame(const Word &Item, unsigned FrameNum)
{
    
}
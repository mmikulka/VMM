//
//  RAM.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#ifndef RAM_hpp
#define RAM_hpp

#include <stdio.h>
#include <array>
#include "Word.h"

struct Status
{
    bool accessed = false;
    bool dirty = false;
};

class RAM
{
public:
    RAM();
    Word read(unsigned frameNum);
    void addFrame(const Word &Item, unsigned FrameNum);
private:
    static std::array<Word, 256> frames;
    static std::array<Status, 256> statuses;
};

#endif /* RAM_hpp */

//
//  MemoryManager.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#include <stdio.h>
#include <queue>
#include "Word.h"

class MemoryManager
{
public:
    MemoryManager();
    void pageIn(Word & item);
private:
    std::queue<Word> freeFrames;
};

#endif /* MemoryManager_hpp */

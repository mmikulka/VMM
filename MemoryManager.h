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
#include "BackingStore.h"
#include "RAM.h"

class MemoryManager
{
public:
    MemoryManager();
    void pageIn(Word & item);
    void read(Word & pageNumber);
private:
    static std::queue<unsigned> freeFrames;
};

#endif /* MemoryManager_hpp */

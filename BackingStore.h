//
//  BackingStore.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#ifndef BackingStore_hpp
#define BackingStore_hpp

#include <stdio.h>
#include <iostream>
#include "Word.h"

class BackingStore
{
public:
    BackingStore();
    
    void read(const Word&);
    
    ~BackingStore();
private:
    std::ifstream file;
};
#endif /* BackingStore_hpp */

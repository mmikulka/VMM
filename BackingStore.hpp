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
#include <fstream>
#include "Word.hpp"

class BackingStore
{
public:
    BackingStore();
    
    void read(Word&);
    
    ~BackingStore();
private:
    std::fstream file;
};
#endif /* BackingStore_hpp */

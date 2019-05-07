//
//  BackingStore.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "BackingStore.hpp"


BackingStore::BackingStore()
{
    file.open("backingstore.bin");
}

void BackingStore::read(Word& pagenumber)
{
    
}

BackingStore::~BackingStore()
{
    file.close();
}

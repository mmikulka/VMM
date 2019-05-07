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

Word BackingStore::read(Address & addr)
{
    Word item;

    Word pageNum = addr.page();

    file.seekg(pageNum.value_);

    file.read(item.value_, std::ios::out);

    return item;
}

BackingStore::~BackingStore()
{
    file.close();
}

//
//  BackingStore.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "BackingStore.h"

BackingStore::BackingStore()
{
    file.open("addresses.txt");
}

void BackingStore::read(const Word&)
{
}

BackingStore::~BackingStore()
{
    file.close();
}

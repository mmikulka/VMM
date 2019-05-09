//
//  BackingStore.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright � 2019 Matthew Mikulka. All rights reserved.
//

#include "BackingStore.hpp"


BackingStore::BackingStore()
{
	file.open("BACKING_STORE.bin");
}

Word BackingStore::read(Address & addr)
{
	/*Word item;

	Word pageNum = addr.page();

	file.seekg(pageNum.value_ * sizeof(uint32_t));

	file >> item.value_;

	return item;*/
    
    Word item;
    
    Word pageNum = addr.page();
    
    uint32_t * buffer = new uint32_t[64];
    
    file.seekg(pageNum.value_ * (sizeof(buffer)));
    
    file.read((char*)buffer, sizeof(buffer));
    
    //std::cout << (uint32_t *)buffer[1] << std::endl;
    
    for (int i = 0; i < (2); i++) {
        std::cout << (uint32_t *)buffer[i] << '\t';
    } std::cout << std::endl;
    
    return item;
}

BackingStore::~BackingStore()
{
	file.close();
}

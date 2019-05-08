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
		Word item;

		Word pageNum = addr.page();

		uint32_t * buffer = new uint32_t[64];

		file.seekg(pageNum.value_ * (sizeof(buffer)));

		file.read((char*)buffer, sizeof(buffer));

		std::cout << buffer[1] << std::endl;

		return item;
}

BackingStore::~BackingStore()
{
	file.close();
}

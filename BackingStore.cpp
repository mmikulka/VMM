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



char* BackingStore::read(Word & pageNum)
{

	char *buffer = new char[256]; // I reccomend a smart pointer

	file.seekg(static_cast<uint64_t>(pageNum.value_) * 256);

	file.read(buffer, 255);

	std::cout << static_cast<int>(buffer[1]) << std::endl;

	return buffer;
}

BackingStore::~BackingStore()
{
	file.close();
}
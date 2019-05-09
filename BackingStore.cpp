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

	char * buffer = new char[256]; // I reccomend a smart pointer 

	file.seekg(static_cast<uint64_t>(pageNum.value_) * (sizeof(buffer)));

	file.read((char*)buffer, sizeof(buffer));

	std::cout << static_cast<unsigned char>(buffer[1]) << std::endl;

	return buffer;
}

BackingStore::~BackingStore()
{
	file.close();
}
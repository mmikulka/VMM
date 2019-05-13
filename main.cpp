//
//  main.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright ? 2019 Matthew Mikulka. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include "backingStore.h"
//#include "MemoryManager.h"
#include "MMU.hpp"
//#include "RAM.h"
//#include "Word.hpp"

using namespace std;

int main()
{

	uint32_t temp = 0;
	Address logAddr;
	MemoryManager manager;
	bool loopCheck = true;
	MMU mem_man_un;
	unsigned char data;
	int count = 0;
	while (cin >> temp) //<addresses.txt> 2|output.txt
	{
		while (loopCheck)
		{
			try
			{
				logAddr.value_ = temp;
				data = mem_man_un.read(logAddr);
				loopCheck = false;
			}
			catch (MMU::PageFault p)
			{
				manager.pageIn(p.pageNumber_);
			}
		}
		count++;
		cout << hex<< static_cast<unsigned int>(data) << endl; 
		loopCheck = true;
	}

	cout << "TLB Hits: " << mem_man_un.TLBAccesses() << endl;
	cout << "Page Faults: " << mem_man_un.pageFaults() << endl;
	cout << "end of program" << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}

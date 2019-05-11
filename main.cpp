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
	//if (argc < 2)
	//{
	//	cout << "You put in the wrong amount of files" << std::endl;
	//	cin.get();
	//	return 0;
	//}
	//else
	//{

		uint32_t temp = 0;
		Address logAddr;
		//ifstream inFile;
		MemoryManager manager;
		bool loopCheck = true;
		MMU mem_man_un;
		//inFile.open(argv[1], ios::out);
		unsigned char data;
		while (cin >> temp) //<addresses.txt> 2|output.txt
		{
			while (loopCheck)
			{
				try {
					//unsigned char data;
					logAddr.value_ = temp;
					data = mem_man_un.read(logAddr);
					loopCheck = false; 
				}
				catch (MMU::PageFault p)
				{
					manager.pageIn(p.pageNumber_);
				}
			}
			cout << static_cast<unsigned int>(data) << '\n';
			loopCheck = true; 
		}

	//}
	cout << "TLB accesses: "<< mem_man_un.TLBAccesses() << endl;
	cout << "TLB Faults: "<< mem_man_un.TLBFaults() << endl;
	cout << "end of program" << endl;
	cin.clear();
	cin.ignore(256, '\n');
	//cin.getline();
	cin.get();
	
	//system("PAUSE");
	return 0;
}

//
//  main.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include "backingStore.h"
//#include "MemoryManager.h"
#include "MMU.hpp"
//#include "RAM.h"
#include "Word.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc < 2)
    {
        cout << "You put in the wrong amount of files" << std::endl;
        return 0;
    }
    else
    {

        uint32_t temp;
        Address logAddr;
        ifstream inFile;
        MMU MemManagerUnit;
        inFile.open(argv[1],ios::out);

        while (inFile >> temp)
        {
            logAddr.value_ = temp;
            MemManagerUnit.read(logAddr);
            cout << logAddr.value_;
        }

    }

    cout << "test" << endl;
    return 0;
}

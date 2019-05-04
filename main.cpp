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
#include "MMU.h"
//#include "RAM.h"
#include "Word.h"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc < 2)
    {
        cout << "You put in the wrong amount of files" << std::endl;
        return 0;
    }
    else
    {

        u_int32_t temp;
        Address logAddr;
        ifstream inFile;
        //MMU * MemManagerUnit = new MMU();
        inFile.open(argv[1],ios::out);

        while (inFile >> temp)
        {
            logAddr.value_ = temp;
            //MemManagerUnit->read(logAddr);
            cout << logAddr.value_;
        }

    }

    cout << "test" << endl;
    return 0;
}

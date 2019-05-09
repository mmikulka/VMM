//
//  PRA.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "PRA.hpp"

PRA::PRA(){
    infile.open("BACKING_STORE.bin");
}

PRA::pull_frame_from_b_store(Word &pageNum){
    /*
     1) i'm not sure if here i'm going to use seekg to retrieve the
        frame from the backing store
     
     2) ...i'm guessing we go into the "RAM" class and sift through
        the frames there instead of having a 'frames' variable here
        code will be similar to the "pageIn()" function in RAM
     */
}

PRA::~PRA(){
    infile.close();
}

//
//  PRA.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef PRA_hpp
#define PRA_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include "BackingStore.hpp"
#include "Word.hpp"


class PRA{
public:
    PRA();
    virtual Word select_frame(Address &frame);
    //void pull_and_replace_frame
    void pull_frame_from_b_store(Word &pageNum);
    ~PRA();
    
protected:
    /*
        the variables that both child classes are going to use
     */
    std::string reference_string;
    Address victim_frame;
    std::fstream infile;
    
};

#endif /* PRA_hpp */

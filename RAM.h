//
//  RAM.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#ifndef RAM_hpp
#define RAM_hpp

#include <stdio.h>
#include "Word.h"

struct Status
{
    bool accessed = false;
    bool dirty = true;
};

class Ram
{
public:
    Ram();
    void read();
private:
    Word items[256];
    Status Statuses[256];
};



#endif /* RAM_hpp */

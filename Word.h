//
//  Word.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/29/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>

struct Word
{
    u_int32_t value_;
};

struct Address
{
    Word address();
    Word displacement();
    Word fram();
    Word page();
};


#endif /* Word_hpp */

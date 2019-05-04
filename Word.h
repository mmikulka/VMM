//
//  Word.hpp
//  VMM
//
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>

struct Word
{
    public:
    u_int32_t value_;

    u_int32_t frame;

};



struct Address: Word
{
    public:
    u_int32_t address();
    Word displacement();
    Word frame();
    Word page();
};


#endif /* Word_hpp */

//
//  Word.hpp
//  VMM
//
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <stdint.h>

struct Word
{
    public:
    uint32_t value_;

    uint32_t frame;

};



struct Address: Word
{
    public:
    uint32_t address();
    Word displacement();
    Word frame();
    Word page();
};


#endif /* Word_hpp */

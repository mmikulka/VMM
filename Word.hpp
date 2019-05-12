//
//  Word.hpp
//  VMM
//
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include "constVars.hpp"

struct Word
{
public:

	uint32_t value_;

};



struct Address : Word
{
public:
	uint32_t address();
	uint32_t displacement();
	Word frame();
	Word page();
	Address& operator=(const Address& rhs);
	Address& operator=(const Word& rhs);
};


#endif /* Word_hpp */
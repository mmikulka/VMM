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

struct Word
{
public:
	uint32_t value_;

	uint32_t frame;

};



struct Address : Word
{
public:
	uint32_t address();
	Word displacement();
	Word frame();
	Word page();
	Address& operator=(const Address& rhs);
	Address& operator=(const Word& rhs);
};


#endif /* Word_hpp */
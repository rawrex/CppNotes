#include <iostream>

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}
class padding {};

// Data structure alignment is the way data is arranged and accessed in computer memory.
// It consists of three separate but related issues:
//	- Data alignment,
//	- Data structure padding,
//	- Packing

// The CPU in modern computer hardware performs reads and writes 
// Most efficiently when the data is naturally aligned.
//
// "Natural" alignment means aligned to its own type width.
// So, the first one, Data Aliginment is the aligning of elements according to their natural alignment.
//
// To ensure natural alignment, it may be sometimes necessary to insert some padding 
// between structure elements or after the last element of a structure.
// E.g. on a 32-bit machine,
// A data structure containing a 16-bit value followed by a 32-bit value could have 16 bits of padding 
// between the 16-bit value and the 32-bit value to align the 32-bit part on a 32-bit boundary.
//
// As to the Packing, we can pack the data structure, omitting the padding,
// Which may lead to slower acces, but uses less memory.
// E.g. if we were to pack the above example, we would've used 3/4 of the memory then.

struct MyData
{
    short Data1;
    short Data2;
    short Data3;
};

// If the type "short" is stored in two bytes of memory 
// then each member of the data structure depicted above would be 2-byte aligned.
// Data1 would be at offset 0, Data2 at offset 2, and Data3 at offset 4.
// The size of this structure would be 6 bytes.

void padding_example()
{
	print(sizeof(char));	// On my machine prints 1
	print(sizeof(short));	// On my machine prints 2
	print(sizeof(int));		// On my machine prints 4
	
	// To maintain proper alignment the translator normally inserts additional unnamed data members 
	// so that each member is properly aligned.
	// In addition, the data structure as a whole may be padded with a final unnamed member.
	struct Data1
	{
		char ch;			// size 1
		padding one;		// pad 1 byte to add up to the size of the next member
		short sh;			// size 2
		int i;				// size 4, offset 4, no padding needed
	};

	// If not for alignment, int member should be placed at the offset 3
	// And then span its four bytes, making the whole data structure to span seven bytes.

	print(sizeof(Data1));	// Prints 8 on my machine
}

void declaration_order_example()
{
	// Same structure as in the above example...
	struct Data1
	{
		char ch;			// size 1
		padding one;		// pad 1 byte to add up to the size of the next member
		short sh;			// size 2
		int i;				// size 4, offset 4, no padding needed
	};
	print(sizeof(Data1));	// Prints 8 on my machine

	// But now let's look at a different declarations order
	struct Data2
	{
		short sh;			// size 2
		padding two;		// add up to 4
		int i;				// size 4, offset 4
		char ch;			// size 1
		padding three;		// need to add up to the whole structure
	};
	print(sizeof(Data2));	// Prints 12 on my machine

	// Padding is only inserted when a structure member is followed by a member 
	// with a larger alignment requirement or at the end of the structure.
	// By changing the ordering of members in a structure,
	// it is possible to change the amount of padding required to maintain alignment.

	struct Data3
	{
		int i;				// size 4
		short sh1;			// size 2
		short sh2;			// size 2
		char ch;			// size 1
		padding three;
	};
	print(sizeof(Data3));	// Prints 12 on my machine

	// Note, if members are sorted by descending alignment requirements 
	// a minimal amount of padding is required.
}

int main()
{
	// padding_example();
	declaration_order_example();
}

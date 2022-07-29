#pragma pack(1)
#include <iostream>
#include "../../Concurrency/JThread.h"

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}

// It’s common knowledge that on all modern x86, x64, Itanium, SPARC, ARM and PowerPC processors,
// plain 32-bit integer assignment is atomic as long as the target variable is naturally aligned.

void run_threads(int& integer)
{
	JThread thread1([&integer]()
	{
		while(true)
			integer = 1;
	});
	JThread thread2([&integer]()
	{
		while(true)
			integer = 0;
	});
	
	while(true)
		print(integer);
}

void plain_int_example()
{
	int plain_int = 0;	
	run_threads(plain_int);
}

struct Natural
{
	int plain_int = 0;
};
struct NotNatural
{
	char ch;
	int plain_int = 0;
};
void non_natural_alignment_example()
{
	NotNatural not_natural_structure;
	run_threads(not_natural_structure.plain_int);
}


int main() {

	print(sizeof(Natural));
	print(sizeof(NotNatural));

	//non_natural_alignment_example();
}

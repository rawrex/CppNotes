#pragma pack(1)
#include <iostream>
#include "../../Concurrency/JThread.h"

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}

// it’s common knowledge that on all modern x86, x64, Itanium, SPARC, ARM and PowerPC processors,
// plain 32-bit integer assignment is atomic as long as the target variable is naturally aligned.

int main() {
	
	struct Natural
	{
		int plain_int = 0;
	};
	struct NotNatural
	{
		char ch;
		int plain_int = 0;
	};

	JThread thread1([&plain_int]()
	{
		while(true)
			plain_int = 1;
	});
	JThread thread2([&plain_int]()
	{
		while(true)
			plain_int = 0;
	});

	while(true)
		print(plain_int);

	print(sizeof(int));

}

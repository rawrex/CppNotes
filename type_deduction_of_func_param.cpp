#include <iostream>

void foo()
{
	static std::size_t counter = 0;
	++counter;
	std::cout << counter << std::endl;
}

template <typename T>
void takeVal(T func)
{
	func();
}	

template <typename T>
void takeRef(T & func)
{
	func();
}	

template <typename T>
void takePtr(T * func)
{
	func();
}	

int main() {
	takeRef(foo);
	takeRef(foo);
	takeRef(foo);

	takeVal(foo);
	takeVal(foo);
	takeVal(foo);
		
	takePtr(foo);
	takePtr(foo);
	takePtr(foo);
}

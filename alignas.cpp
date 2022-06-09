#include <iostream>
#include <string>
#include <cmath>

constexpr size_t sz = static_cast<size_t>(std::pow(2,6));

struct alignas(sz) Foo {
	std::string s1;
	int i1;
	std::string s2;
};
void print(std::string msg)
{
	std::cout << msg << std::endl;
}
void print(std::string msg, const size_t & n)
{
	std::cout << msg << ": " << n << std::endl;
}


int main() {

	const size_t 
		size_str = sizeof(std::string),
		size_int = sizeof(int),
		align_str = alignof(std::string),
		align_int = alignof(int),
		size_foo = sizeof(Foo),	
		align_foo = alignof(Foo);	
	
	print("sizeof(int)", size_int);
	print("alignof(int)", align_int);
	print("sizeof(std::string)", size_str);
	print("alignof(std::string)", align_str);
	
	std::cout << '\n';

	print("Specified alignment of Foo", sz);
	print("sizeof(Foo)", size_foo);
	print("alignof(Foo)", align_foo);
}

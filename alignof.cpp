#include <iostream>
#include <string>

// Demonstration of built-in and STL alignments
struct Foo {
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
		size_foo = sizeof(Foo);	
	
	print("sizeof(int)", size_int);
	print("alignof(int)", align_int);
	print("sizeof(std::string)", size_str);
	print("alignof(std::string)", align_str);
	
	std::cout << '\n';

	const size_t calculate = 2*size_str + size_int + (align_str - align_int);

	print("Foo is equal to", calculate);
	print("Foo = 2 * sizeof(std::string) + sizeof(int) + (alignof(std::string) - sizeof(int))", calculate);
	
	std::cout << '\n';
	print(size_foo == calculate ? "Confirmed!" : "Wrong");

	std::cout << '\n';
	print("sizeof(Foo)", size_foo);
}

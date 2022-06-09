#include <cmath>
#include <iostream>
#include <array>

struct Foo {
	int i1;
	char c1;
	int i2;
	char c2;
};


struct Bar {
	int i1;
	int i2;
	char c1;
	char c2;
};

int main() {
	constexpr size_t size = std::pow(2, 15);
	std::array<Foo, size> foo;
	std::array<Bar, size> bar;
	std::cout << "sizeof(foo): " << sizeof(foo) << std::endl;
	std::cout << "sizeof(bar): " << sizeof(bar) << std::endl;
	
	std::cout << "Differrence: " << sizeof(foo) - sizeof(bar) << std::endl;
}

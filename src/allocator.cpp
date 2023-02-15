#include <iostream>
#include <memory>
#include <string>

int main() {

	std::allocator<std::string> a;
	auto p = a.allocate(10);

	// We can construct in different order
	a.construct(p+1, 6, 'y');
	a.construct(p, 6, 'x');

	// We can (?) use the placement new to construct 
	new (p+2) std::string(6, 'z');

	// These three are constructed
	std::cout << p[0] << ' ' << p[1] << ' ' << p[2] << std::endl;

	// This one is not 
	p[3] = std::string("Foobar");
	std::cout << *(p+3) << std::endl;
}

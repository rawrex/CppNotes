#include <iostream>
#include <memory>
#include <string>

int main() {

	std::allocator<std::string> a;
	auto p = a.allocate(10);

	new (p+2) std::string(6, 'z');
	a.construct(p+1, 6, 'y');
	a.construct(p, 6, 'x');

	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
}

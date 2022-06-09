#include <iostream>
#include <string>

int main() {
	std::string s("foo");
	const char * p = s.c_str();
	std::cout << *p << std::endl;
	s[0] = 'X';
	std::cout << *p << std::endl;
}

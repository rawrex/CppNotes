#include <iostream>
#include <bitset>
#include <string>
#include <limits>

void basicExample()
{
	// The bitset size specification must be a constant expression
	// All ones, "1", with as many bits as the unsigned int type has
	std::bitset<sizeof(unsigned) * 8> data(std::numeric_limits<unsigned>::max());
	std::cout << data << std::endl;

	std::string data_string_A("11001010");
	// The ctors that take a string or char pointer are explicit
	std::bitset<8> data_from_string_A(data_string_A);
	std::cout << data_from_string_A << std::endl;

	std::string data_string_B("xxooxoxo");
	std::bitset<8> data_from_string_B(data_string_B, 0, std::string::npos, 'o', 'x');
	std::cout << data_from_string_B << std::endl;
}

int main()
{
	basicExample();
}

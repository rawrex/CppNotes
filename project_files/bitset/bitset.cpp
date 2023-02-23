#include <iostream>
#include <bitset>
#include <string>
#include <limits>

void basicExample()
{
	// All ones, "1", with as many bits as the unsigned int type has
	std::bitset<sizeof(unsigned) * 8> data(std::numeric_limits<unsigned>::max());
	std::cout << data << std::endl;

	std::string data_string("xxooxoxo");
	std::bitset<8> data_from_string(data_string, 0, std::string::npos, 'o', 'x');
	std::cout << data_from_string << std::endl;
}

int main()
{
	basicExample();
}

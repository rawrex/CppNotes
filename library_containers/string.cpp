#include <iostream>
#include <string>

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}

void additional_ways_to_construct_string()
{
	const char cp[] = {'f', 'o', 'o', ' ', 'b', 'a', 'r', '\n'};
	const size_t size = 4;
	const size_t length = 1;
	const size_t position = 2;

	// In addition to standard container ctor, string has few special forms
	//
	// s1 will be a copy of the first n characters in the array to which cp points
	// That array must have at least "size" characters
	std::string s1(cp, size);	

	std::string s2(s1, position);	

	std::string s3(s1, position, length);
	
	print(s1);
	print(s2);
	print(s3);
}

int main() {

	additional_ways_to_construct_string();

}

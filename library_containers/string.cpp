#include <iostream>
#include <string>

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}

void additional_ways_to_construct_string()
{
	const char cp[8] = {'f', 'o', 'o', ' ', 'b', 'a', 'r', '\n'};

	// In addition to standard container ctor, string has few special forms

	// s1 will be a copy of the first n characters in the array to which cp points
	// That array must have at least "size" characters.
	//
	// Note, ordinarly we need the const char array to be null-terminated
	// if we want to construct a string from it.
	//
	// In case of a string constructor that takes a count of how many chars to copy
	// We can use a non-null-terminated character array.

	const size_t foo_size = 3;
	const size_t foo_bar_size = 7;
	const size_t wrong_size = 21;

	std::string s_foo(cp, foo_size);	
	std::string s_foo_bar(cp, foo_bar_size);
	std::string s_wrong(cp, wrong_size);		// Note, no waringings issued here

	print(s_foo);
	print(s_foo_bar);
	print(s_wrong);



	// "s_bar_copy" is a copy of characters in "s_foo_bar", starting at the index "position"
	// Undefined if "position" is greater than the "s_foo_bar.size()" 

	const size_t position = 4;
	const size_t position_wrong = 9;

	std::string s_bar_copy(s_foo_bar, position);	
	print(s_bar_copy);

	// terminate called after throwing an instance of 'std::out_of_range'
	// what():  basic_string::basic_string: __pos (which is 9) > this->size() (which is 7)
	// Aborted (core dumped)
	// std::string s_bar_wrong(s_foo_bar, position_wrong);	


	
	// "s_b_copy" is a copy of length characters from "s_foo_bar",
	// starting at index "position".
	//
	// Undefined if "position" is greater than "s_foo_bar".
	// Regardless of the value of "length" copies at most "s_foo_bar.size()" - "position" elements.

	const size_t length = 1;
	const size_t length_wrong = 21;
	std::string s_b_copy(s_foo_bar, position, length);
	std::string s_bar_copy_not_wrong(s_foo_bar, position, length_wrong);

	print(s_b_copy);
	print(s_bar_copy_not_wrong);
	
}

int main() {

	additional_ways_to_construct_string();

}

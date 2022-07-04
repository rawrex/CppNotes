#include <iostream>



int main() {

	// Ends the current line and flushes the buffer
	std::cout << "endl" << std::endl;

	// Flushes the stream but does not adds any characters to the output
	std::cout << "flush" << std::endl;

	// Inserts a null character into the buffer and then flushes it
	std::cout << "ends" << std::endl;

}

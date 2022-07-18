#include <iostream>

// Several unformatted IO operations deal with a stream one byte at a time.
// The unformatted IO operations "get" and "put" read and write characters one at a time.
// These read (not ignore) whitespace.

// input_stream.get(ch)			- put the next byte from the istream in character ch; returns input_stream
// output_stream.put(ch)		- put the next character ch onto the ostream; returns output_stream
// input_stream.get()			- returns the next byte from istream as an int
// input_stream.putback(ch)		- put the character ch back on istream; returns input_strea
// input_stream.unget()			- move input_stream back one byte; returns input_stream

void example_get_put()
{
	char ch;
	while(std::cin.get(ch))		// Exactly as we would have used std::noskipws
		std::cout.put(ch);
}

int main() {

	// 

}

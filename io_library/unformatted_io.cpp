#include <iostream>

// Several unformatted IO operations deal with a stream one byte at a time.
// The unformatted IO operations "get" and "put" read and write characters one at a time.
// These read (not ignore) whitespace.

// input_stream.get(ch)			- put the next byte from the istream in character ch; returns input_stream
// output_stream.put(ch)		- put the next character ch onto the ostream; returns output_stream
// input_stream.get()			- returns the next byte from istream as an int
// input_stream.putback(ch)		- put the character ch back on istream; returns input_strea
// input_stream.unget()			- move input_stream back one byte; returns input_stream
// input_stream.peek()			- returns the next byte as an int but does not removes it

void example_get_put()
{
	char ch;
	while(std::cin.get(ch))		// Exactly as we would have used std::noskipws
		std::cout.put(ch);
}


// Sometimes we need to read a character from the stream just to put it back onto the stream:
// peek(), 		returns the copy of the next character on the stream,
//				does not change the stream.
// unget(),		back up, so that the value that was last returned is still on the stream,
//				we can use unget() even if we do not know what value was last taken from the stream.
// putback(),	returns the last value read from the stream,
// 				but takes the arg that must be the same as the one that was last read,
//				in other words, put back what you just took, knowing what you just have taken.

int main() {

	// 

}

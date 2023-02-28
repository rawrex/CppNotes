#include "unformatted_io.h"
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
// peek(),			returns the copy of the next character on the stream,
//					does not change the stream.
// unget(),			back up, so that the value that was last returned is still on the stream,
//					we can use unget() even if we do not know what value was last taken from the stream.
// putback(arg),	returns the last value read from the stream,
//					but takes the arg that must be the same as the one that was last read,
//					in other words, put back what you just took, knowing what you just have taken.
//
// We are guaranteed to be able to put back at worst one value before the next read;
// Note, we are not guaranteed to be able to call putback() ot unget() successively without a read.

void example_peek()
{
	char ch_peek = '\0';
	char ch_get = '\0';

	// Copy the next char on the stream, leaving the stream intact
	ch_peek = std::cin.peek();
	
	// Get the same character from the stream, stream is changed now
	std::cin.get(ch_get);

	// These prints are the same
	std::cout << ch_peek << std::endl;
	std::cout << ch_get << std::endl;
}
void example_unget()
{
	char ch_before_unget = '\0';
	char ch_after_unget = '\0';

	// Request an input from the stdin
	std::cin.get(ch_before_unget);

	// The value we've put into the ch_before_unget is now on the stream again
	std::cin.unget();
	
	// No new input will be requested from a user,
	// there's already a character present at the stdin
	std::cin.get(ch_after_unget);

	// These prints print the same value
	std::cout << ch_before_unget << std::endl;	
	std::cout << ch_after_unget << std::endl;
}
void example_putback()
{
	char ch_get_first_time = '\0';
	char ch_get_second_time = '\0';

	// Get a character from the stream
	std::cin.get(ch_get_first_time);
	
	// Put back the same character back onto the stream
	std::cin.putback(ch_get_first_time);

	// We can get the character once again,
	// No user interaction needed, since the character is already on the stream
	std::cin.get(ch_get_second_time);

	// These prints are the same
	std::cout << ch_get_first_time << std::endl;
	std::cout << ch_get_second_time << std::endl;

	// In the ch_get_second_time we've got the value we've put back, the same one, we got on the first get()
	// The stream is changed for the second time and does not contain any characters. (note, the use of the Return will insert a newline)

	char ch_other = 'y';
	// Now, let's try to putback some other value, not the one we've took
	// Does not fail for some reason. Will do a research on the case
	std::cin.putback(ch_other);
}

void example_int_returns()
{
	// The peek and the get called with no arguments return a character from the input stream as an int
	// This way these operations can return an end-of-file marker.
	//
	// A given char set is allowed to use every value in the char range to represent an actual character.
	// Thus, there is no extra value in that range to use to represent end-of-file
	// The library uses a negative value to represent end-of-file,
	// which is thus guaranteed to be distinct from any legitimate character value.
	//
	// Rather than requiring us to know the actual value returned,
	// the cstdio header defines a const named EOF 
	// that we can use to test if the value returned from get is end-of-file:
	std::cout << "EOF value: " << EOF << std::endl;

	// It is essential that we use an int to hold the return from these functions:

	int ch; 								// Use an int, not a char to hold the return from get()
	while ((ch = std::cin.get()) != EOF)	// Loop to read and write all the data in the input
		std::cout.put(ch);

}

void unformatted_io_main() 
{
	// example_peek();
	// example_unget();
	example_putback();
	// example_int_returns();
}

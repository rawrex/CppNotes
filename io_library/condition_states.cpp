#include <iostream>
#include <fstream>
#include <sstream>

// When working with IO, errors are inevitable.
// Some errors are recoverable and some occur deep within the system.
// So, their handling is out of the scope of the program.
// The IO lib defines a colleciton of functions and status flags 
// That let us access and manipulate the condition state of a stream.

// We can work (read/write) only on a stream that is not in an error.
// Thus, we should ordinary check whether a stream is valid before attempt to use it.
// The easiest way is to use the stream object as a condition:

while (std::cin >> foo)
{
	// Do work...
}

// Machine-dependent integral type used as a collection of bits for fetching the state of a stream
// (stream denotes one of the IO types)
stream::iostate;	

// The IO classes define four constexpr values of type iostate which represent a particular bit pattern.
// These are used to indicate particular kinds of IO conditions.
// We use these with bitwise operators to test/set one or more flags.

// Indicates a system-level failure.
// An unrecoverable read or write error.
// It is usually not possible to use a stream once this bit has been set.
stream::badbit;

// Set after a recoverable error 
// (e.g. read a character when a numeric value was expected).
stream::failbit;

// Reading up to the end-of-file sets eofbit.
// If end-of-file does not follow a valid input, failbit is also set.
stream::eofbit;

// Guaranteed to have 0 value.
// Indicates no failing of the stream.
// If any of the above three states is set, then the condition that evaluates the stream will fail.
stream::goodbit;


// The lib also defines a set of funcitons to interrogate the state of these falgs.

// Returns true if none of the error bits is set.
strm.good();

// These three return true if the correspoding bit is on.
strm.eof();
strm.bad();
strm.fail();	// fail() returns true if failtbit or badbit is set
				// So to determine the overal state of stream we use either good() or fail()

// These two are equivalent in the conditional sense:
if (std::cin);
if (std::cin.good());	// ?
if (!std::cin.fail());

// Returns an iostate value of the current state of the stream
strm.rdstate();

// Turns on the given condition bit(s)
strm.setstate();

// Overloaded, one overload takes no arguments, turns off all the failure bits
// The other takes an argument of type iostate which represents the flags we want to clear
// Note, if state is goodbit (which is zero) all error flags are cleared,
// That's why goodbit is guaranteed to be zero.
void clear (iostate state = goodbit);
strm.clear();

// In the case that no stream buffer is associated with the stream when this function is called,
// the badbit flag is automatically set (no matter the value for that bit passed in argument state).
// Changing the state may throw an exception,
// depending on the latest settings passed to member exceptions.


// To turn on a single condition flag, we use rdstate along with bitwise operators to produce desired result
std::cin.clear

int main() {

}

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

// The IO classes define four constexpr values of type iostate which represent a particular bit patter.
// These are used to indicate particular kinds of IO conditions.
// We use these with bitwise operators to test/set one or more flags.
stream::badbit;
stream::failbit;
stream::eofbit;
stream::goodbit;

strm.eof();
strm.fail();
strm.bad();
strm.good();
strm.clear();

strm.eof();
strm.setstate();
strm.rdstate();

int main() {

}

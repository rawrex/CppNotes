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

// stream denotes one of the IO types
stream::iostate;
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

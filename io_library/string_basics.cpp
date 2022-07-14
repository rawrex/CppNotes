#include <iostream>
#include <sstream>

// The sstream header defined types which we can use to do in-memory IO
// These types read and write to an underlying std::string as if it was an IO stream.

// At the low level,
// the class essentially wraps a raw string device implementation of std::basic_stringbuf
// into a higher-level interface of std::basic_iostream.

// There are two specializations for common character types are also defined:
//	- stringstream 		basic_stringstream< char >
//	- wstringstream 	basic_stringstream< wchar_t >

// We have the std::istringstream which reads a string;
// The std::ostringstream which writes to a string;
// And the std::stringstream which does both.

// These types inherit from the iostream header types (just like fstream).
// These types also introduce some specific operations as well (just like fstream).

std::string string_a("Foo bar");
std::stringstream string_stream(string_a);		// Holds a copy of the str, this ctor is explicit

std::string string_b = string_stream.str();		// Returns a copy of the internal string

std::string string_c("Baz qux");
string_stream.str(string_c);					// Copies string into the stream, returns void

int main() {

}

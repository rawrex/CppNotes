#include <iostream>

// In general, a system will support a random access to the data on streams
// The library provides a set of funcitons to seek to a given location 
// and to tell the current location in the associated stream.
//
// So, note the IO is system dependent.

// The seek and tell functions are defined for all the stream types
// But whether they do anything depends on the device they are called on, to which the stream is bound.
// On most systems, streams bound to cin, cout, cerr, clog do not support random access IO.
// If we were to call the random access funcitons on them, the calls will fail at run-time,
// Leaving the stream in invalid state.

void random_access_on_cin_example() 
{
	auto current_pos = std::cin.tellg();	// Get the current position marker
	std::cout << current_pos << std::endl;	// Prints -1 on my machine
	std::cin.seekg(21, std::cin.beg);		// Supposed seek to some location
	current_pos = std::cin.tellg();			// Update the current position marker
	std::cout << current_pos << std::endl;	// Still prints -1 on my machine
}

// Note, in general, we should use the higher-level abstracitons porvided by the library.
// Use of the low-level routines is highly error-prone.
// E.g. it is a common error to use char type for the return from the peek() or get(), rather than int.
// Thus, unabling to check for the EOF properly.



// To support random access, the IO types maintain a marker,
// used to determine where the next read/write will be performed.
//
// We have two functions: one repositions the marker by seeking to a given position.
// Another one tells us the current position.
//
// There are two pairs of seek and tell functions, for input and output.
// With the "g" suffix (for "get"), and "p" suffix (for "put").
// We can use the "g" version on std::istream (ifstream, istringstream)
// And we use the "p" version on std::ostream (ofstream, ostringstream).
// We can use both on the std::iostream (fstream, stringstream).
//
//	tellg()					return the current position of the marker in an IO stream, pos_type type.
//	tellp()					
//
//	seekg(position)			reposition the marker in the IO stream to the given absolute address
//	seekp(position)			pos is ussually a value returned by a previous call to the corresponding tell_().
//
// 	seekp(offset, from)		reposition the marker relatively by "off" (integer) number of characters
// 	seekg(offset, from)		ahead or behind "from", which can be:
//									- "beg", seek to the begining of the file,
//									- "cur", seek to the current position "pos"
//									- "end", end of the stream
//
// Note, here, "offset" and "position" have machine dependent types,
// named "off_type" and "pos_type" accordingly.


// Even though the library maintains two functions for putting and getting from the stream
// It maintains a single marker in the stream for both uses.
// The std::iostream maintains a single buffer both for writing and reading 
// that holds a single marker for the current position in itself.
// The library maps both the "g" and "p" versions to that single marker.
//
// So, note, we must seek() to reposition the marker whenether we want to read or write separately.




int main() {
	random_access_on_cin_example();
}

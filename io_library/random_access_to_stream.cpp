#include <iostream>

// In general, a system will support a random access to the data on streams
// The library provides a set of funcitons to seek to a given location 
// and to tell the current location in the associated stream.
//
// So, note the IO is system dependent.

// The seek and tell functions are defined for all the stream types
// But whether they do anything depends on the device they are called on, to which the stream is bound.
// On most systems, streams bound to cin, cout, cerr, clog do not suppor random access IO.
// If we were to call the random access funcitons on them, the calls will fail at run-time,
// Levaing the stream in invalid state.

// Note, in general, we should use the higher-level abstracitons porvided by the library.
// Use of the low-level routines is highly error-prone.
// E.g. it is a common error to use char type for the return from the peek() or get(), rather than int.
// Thus, unabling to check for the EOF properly.



// To suppor random access, the IO types maintain a marker,
// used to determine where the next read/write will be performed.
//
// We have two functions: one repositions the marker by seeking to a given position.
// Another one tells us the current position.
//
// There are two pairs of seek and tell functions, for input and output.
// Withe the "g" suffix (for "get"), and "p" suffix (for "put").
//
//	- tellg()				return the current position of the marker in an IO stream
//	- tellp()
//
//	- seekg(pos)			reposition the marker in the IO stream to the given absolute address
//	- seekp(pos)			pos is ussually a value returned by a previous call to the corresponding tell_().
//
// 	- seekp(off, from)		reposition the marker relatively by "off" (integer) number of characters
// 	- seekg(off, from)		ahead or behind "from", which can be:
//								- "beg", seek to the begining of the file,
//								- "cur", seek to the current position "pos"
//								- "end", end of the stream




int main() {

}

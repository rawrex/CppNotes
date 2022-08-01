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


int main() {

}

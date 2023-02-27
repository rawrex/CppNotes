#include "format_state_management.h"
#include <iostream>
#include <iomanip>

// In addition to condition state, each iostream object maintains a formatting state.
// Which contorls how IO is formatted.
// The library defines a set of manipulators (an object or a function)
// That we can use to modify the state, as an operand to an IO operator.

// Manipulators can be divided into two categories:
//	- Presentation of numeric values, set/unset pairs
//	- The amount and placement of padding

// Manipulators defined in the std::iostream namespace:
// boolalpha						- true and false as strings
// showbase							- generate prefix
// showpoint						- show decimal point for f.p. with whole values
// showpos							- explicitly display sign of a number
// uppercase						- print 0X and E for scientific
// dec, hex, oct					- numeric bases
// left, right						- where to add fill characters
// internal							- and the fill chars between the sign and the value
// fixed, hexfloat, scientific		- f.p. numbers display mode
// unitbuf							- flush the buffer on every output operation
// skipws							- skip whitespace with input operations
// flush							- flush the ostream buffer
// ends								- insert the null char, then flush
// endl								- insert the null char, then flush
//
// The on/off ones of these has a counterpart that sets the state to the opposite mode.


void format_state_management_main() 
{
	// A manipulator returns the stream to which it is applied, so we can chain operations:
	std::cout << std::boolalpha << true << std::noboolalpha << ' ' << false << std::endl;

	// Specify the base for integer types
	// Note, these three manipulators affect only integral operands,
	// The floating point values are unaffected.
	std::cout << 21 << std::endl;				// Default, decimal
	std::cout << std::oct << 21 << std::endl;	// Octal
	std::cout << std::hex << 21 << std::endl;	// Hexadecimal
	std::cout << std::dec << 21 << std::endl;	// Explicit decimal

	// We can set visual clues for what base we are currently printing in
	// Set, print, then unset the manipulator
	std::cout << std::showbase << std::hex << 21 << std::endl;
	// By default, std::hex are printed in lowercase, we can change that
	std::cout << std::uppercase << 21 << std::endl;
	// Now, set everything back to the defaults
	std::cout << std::noshowbase << std::dec << std::nouppercase << std::endl;

	// For floating point values we can control the following:
	//	- How many digits of precision are printed.
	//	  Default is six digits.
	//	- A hexadecimal, fixed decimal, or scientific notation;
	//	  Default is fixed decimal or scientific notation, depending on the value.
	//	- Whether decimal point is printed for floating point values that are whole numbers;
	// 	  Default is that point is omitted, if there's no decimal part.
	//
	// We can set the precision using either the overloaded member function
	// Or using a special library manipulator object,
	// The std::setprecision, defined in the "iomanip" header,
	// as all other manipulators that take arguments:
	std::cout << std::cout.precision() << std::endl;					// Prints 6
	std::cout << std::cout.precision(8) << std::endl;					// Prints 6,
																		// It returns the previous
	std::cout << std::setprecision(10); 
	std::cout << std::cout.precision() << std::endl;					// Prints 10

	
	// The library provides several manipulators we can use to pad the output:
	//	- setw(n), to specify the minimum space for the next numeric or string value
	//	- setfill(ch), to specify an alternative fill character

	// Other manipulators from the iomanip header:
	//	- setbase(b), output integers in base b
	//	- setprecision(n), which we've already covered above
}
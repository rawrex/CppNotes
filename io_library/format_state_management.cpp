#include <iostream>

// In addition to condition state, each iostream object maintains a formatting state.
// Which contorls how IO is formatted.
// The library defines a set of manipulators (an object or a function)
// That we can use to modify the state, as an operand to an IO operator.

// Manipulators can be divided into two categories:
//	- Presentation of numeric values, set/unset pairs
//	- The amount and placement of padding


int main() {

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

}

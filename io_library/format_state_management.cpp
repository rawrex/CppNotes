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

}

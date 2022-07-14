#include <iostream>

// In addition to condition state, each iostream object maintains a formatting state.
// Which contorls how IO is formatted.
// The library defines a set of manipulators (an object or a function)
// That we can use to modify the state, as an operand to an IO operator.

// Manipulators can be divided into two categories:
//	- Presentation of numeric values
//	- The amount and placement of padding



int main() {

	// A manipulator returns the stream to which it is applied, so we can chain operations:
	std::cout << std::boolalpha << true << std::noboolalpha << ' ' << false << std::endl;

}

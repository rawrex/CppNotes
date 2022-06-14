#include <iostream>

// In general, the constexpr specifier declares 
// that it is possible to evaluate the value of the function or variable at compile time.
// Such variables and functions can then be used where only compile time constant expressions are allowed
// (provided that appropriate function arguments are given).

// Ctors can't be const, but ctors in a literal class can be constexpr functions
// (Recall that a literal class must provide at least one constexpr ctor)

// A constexpr ctor is used to generate objects that are constexpr
// and for parameters or return types in constexpr functions.

// In 11-th standard, a constexpr ctor can be declared as =default or =deleted.
// Otherwise, a constexpr ctor must meet the requirements
//	- for a ctor (must have no return statement)
//	- for a constepxr function (the only executable statement it can have is a return statement)
// As a result, the body of a constexpr ctor is often empty.

class Debug
{
	bool hardware;
	bool input_output;
	bool other;

public:
	constexpr Debug(bool b = true) : hardware(b), input_output(b), other(b) {}
	constexpr Debug(bool hw, bool io, bool o) : hardware(hw), input_output(io), other(o) {}
	constexpr bool any() const { return hardware || input_output || other; }
};

int main() 
{
	constexpr Debug d;
	std::cout << std::boolalpha << d.any() << std::endl;
}

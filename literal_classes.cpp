#include <iostream>
#include <type_traits>

// An aggregate class, whose data members are all of literal type is a literal class.
//
// A non-aggregate class, that meets the following restrictions, is also a literal class:
//	- The data memebers all must have literal type
//	- The class must have at least one constexpr ctor
//	- If a data member has an in-class initializer,
//	  the initializer for a nenber if built-in type must be a constant expression;
//	  for a member of class type, the initializer must use the members own constexpr ctor
//	- The must use default definition for its destructor

struct Literal 
{
	int a;
	int b;
	constexpr int sum() const { return a + b; }
	constexpr Literal() : a(1), b(1) {}
};

int main() 
{
	Literal lit;

	// warning: ‘template<class _Tp> struct std::is_literal_type’ is deprecated
	std::cout << std::is_literal_type<Literal>::value << std::endl;
}

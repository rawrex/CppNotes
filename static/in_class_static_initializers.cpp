#include <iostream>

struct Literal {
	double data_1;
	double data_2;
	constexpr Literal(double d1, double d2) : data_1(d1), data_2(d2) {}
};

constexpr Literal global_data = {1.4141, 1.7320};

struct Foo {

	// error: ISO C++ forbids in-class initialization of non-const static member 
	// Must be const
	// static int data_a = 63;

	// OK, we may provide in-class initializer for data members that have const integer type
	const static int data_b = 42;

	// We must provide an in-class initializer for a static constexpr member 
	constexpr static int data_c = 21;

	// error: ‘constexpr’ needed for in-class initialization of static data member 
	// Not an integral type and not a constexpr
	// const static Literal data_d = {1.4141, 1.7320};

	// OK, the member is a static constexpr and the initializer is a constexpr
	// Such a member is itself a constant expression 
	// and can be used where a constant expression is required
	constexpr static Literal data_d = global_data;

};

// If we use a static memeber only in contexts where the complier can substitute the member's value,
// then we do not need to separetely define the member.
// However, if we use the member in other context in which the value cannot be substituted,
// then we must provide a definition for that member:
//
// E.g. If we pass the Foo::data_b to a function that takes a const int&:
void print(const int& i) { std::cout << i << std::endl; }

// If the initializer is provided in the class,
// the member's definition outside must not specify an initial value:
const int Foo::data_b;


int main() {

	// If we do not define the Foo::data outside of the class' scope, we'll get:
	// undefined reference to `Foo::data_b'
	print(Foo::data_b);

	// Best practice: even if we do have an in-class initializer,
	// We ordinarly should define the member outside the class definition
	// The best place to provide such definition is in a source file with other definitions.
	
}

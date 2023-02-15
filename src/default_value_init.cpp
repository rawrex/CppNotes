#include <iostream>
#include <cassert>

struct Foo {
	// No user-defined ctor
	int x;
};

struct Bar {
	int x;

	// User-defined non-default ctor
	Bar(int) {};
};


int main() {

	// Foo doesn't have a user-supplied ctor, so the complier will provide an implicitly defined one.
	// This ctor does not initialize members of built-in types.
	// Yet the initialization of a instance of the class can be performed by other means...

	// The syntax `Foo()` performs value-initialization of the class instance
	std::cout << Foo().x << std::endl;	// Value initialized
	std::cout << Foo{}.x << std::endl;	// Value initialized

	// The above will only invoke the default constructor if it is user-declared.
	// Otherwise, the `Foo()` will not call the compiler-provided default constructor,
	// but rather will perform a special kind of init that does not involve the ctor of Foo at all.
	// It will directly value-initialize every member of the class.
	// And for built-in types it results in zero-initialization.
	
	// So, the below data member is uninitialized, since no () usage in syntax, but...
	// If you put something on the stack (i.e., auto storage), you will almost certainly get garbage 
	// but on your system that garbage might happen to be somewhat predictable 
	// (to look "meaningful", hence can be hard to debug).
	// And with objects on the stack, changing code in a completely DIFFERENT SOURCE CODE file
	// can change the values you see in an uninitialized data structure.

	Foo foo_a;		// warning: ‘foo_a.Foo::x’ is used uninitialized in this function
	std::cout << "foo_a.x = \t\t" << foo_a.x << std::endl;;	// x contains garbage (may look meaningful)

	// e.g. this code can affect the contents of the foo_a.x:
	Bar b(3.14);
	// warning: ‘b.Bar::x’ is used uninitialized in this function
	std::cout << "b.x = \t\t" << b.x << std::endl;
	// warning: ‘<anonymous>.Bar::x’ is used uninitialized in this function
	std::cout << "Bar(3.14).x = \t\t" << Bar(3.14).x << std::endl;

	// The following initializations will zero-initialize x
	// because they use the explicit () initializer

	Foo foo = Foo();		// Does not use default constructor for `Foo()` part
							// Uses value-initialization feature instead
	assert(foo.x == 0);

	Foo *pfoo = new Foo();	// Does not use default constructor for `Foo()` part
							// Uses value-initialization feature instead
	assert(pfoo->x == 0);
	// Clean up
	delete pfoo;

	// Another example of init that is performed without involving ctor is aggregate initialization
	Foo bar = {};			// Does not use any `Foo` constructors at all. Same as `Foo bar{};` in C++11
	assert(bar.x == 0);

	Foo baz{};				// C++11 style aggregate initialization.
	assert(baz.x == 0);

	// N.B.
	// If you do `Foo() = default;` this would still perform value-initialisation for `new Foo();`
	// and default-initialisation for `new Foo;`

}

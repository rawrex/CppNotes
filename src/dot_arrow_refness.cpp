#include <iostream>
#include <string>

struct Foo {
	std::string name;
	
};

void func(std::string &&) {}

int main() {

	Foo foo{"foobar"};

	// The dot operator yields an lvalue if the object from which the member is fetched is an lvalue;
	// otherwise, the result is an rvalue.

	// In general, we access members through a named-value
	// which will always yield the standard/expected lvalue reference:
	std::string & name_l = foo.name;

	// However, the "dot" will propagate the refness of the object being accessed
	// Means you can implicitly get an rvalue ref of name if foo is an rvalue (XValue):
	std::string && name_r = std::move(foo).name;
	// ...or as a temporary (PRValue)
	func(Foo{"foobar"}.name);

	// This value-propagation is somewhat true of member functions as well.
	// We can control which of the mem.funcs will be called
	// based on the refness of the underlying object using ref-qualifiers.
	// Unlike with a data member, the result of the call need not actually match the value-category;
	// this is just used for determining which function to call as a form of overload resolution.	


	// Arrow Operator
	// 
	// For the default arrow operator (i.e. not a custom operator->), it can only operate on pointers.
	// Pointers, unlike references, don't contain the underlying value-category of the pointee;
	// they only know the value category of the pointer itself.
	
	// For example, std::move on a Person* will yield a Person*&&,
	// an rvalue of the pointer, but not an rvalue of the underlying pointed object.
	// For this reason, dereferencing through operator-> can never yield an rvalue,
	// since the pointee is never known to be an rvalue.	


	// Custom operator-> definitions
	//
	// Any definition of operator-> must return an object which either defines operator->, or is a pointer.
	// This is done because any expression a->b in C++ will recursively call operator-> 
	// until it reaches a pointer in order to perform the dereference. 
	// As we know from above, a pointer does not contain a value category. 
	// So, once we reach this point we cannot get an rvalue.

}

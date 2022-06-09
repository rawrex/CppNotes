#include <iostream>
#include <string>

// It is usually better to supply in-class initializers 
// Especially for the built-in types

class Foo {
	// Value initialized if () or {} form is used
	int i;
	// Default constructed using the string's default ctor
	std::string s;	
	// Uses in-class initializer in case of Foo() and Foo(int) 
	double d = 3.14;

public:
	// Explicit request to generate the default ctor
	// Will use the in-class initializers, if present
	Foo() = default;

	// Explicitly initializes the i member 	
	// For the rest of data members the same process takes place
	// As in the case of the synthesized default ctor (uses in-class values)
	// I.e. members that don't appear in the constructor initializer list
	// are initialized by the in-class initializers or are default inited otherwise
	Foo(int in) : i(in) {}
	
	void show() const 
	{
		std::cout << i << ' ' << d << ' ' << s <<  std::endl;
	}
};

int main() {

	Foo f1;
	f1.show();			// 561754112 3.14 

	Foo f2(1.12);
	f2.show();			// 1 3.14
	
	Foo f3 = Foo();
	f3.show();			// 0 3.14 

}

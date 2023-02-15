#include <iostream>

// https://en.cppreference.com/w/cpp/language/friend#Description

// Deliberately not providing the declaration
// void print(int i)

class Foo
{
	// May not declare outside of the Foo
	// Same for non-const and non-reference param type
	// And for different amount of parameters of different types 
	// (but always inlcuding Foo somewhere)
	friend void print(const Foo& foo)
	{
		std::cout << "print(const Foo&), " << foo.data << std::endl;
	}

	// Must declare outside of the Foo
	// Same for any other than Foo user-defined classes as parameters
	friend void print(int i)
	{
		std::cout << "print(int), " << i << std::endl;
	}

	// Data member
	int data = 21;

public:
	void function() const 
	{
		// Ok
		print(Foo());

		// error: ‘print’ was not declared in this scope
		// print(42);
	}
};

int main() {
	Foo foo;
	foo.function();
}

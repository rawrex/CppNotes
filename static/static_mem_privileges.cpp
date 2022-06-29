#include <iostream>

// Since static members exist outside any object,
// they can be used in ways that would be illegal for non static data members:

// A static data member can have an incomplete type.
// Means, we can have a mem of the same type as its enclosing class
struct Foo
{
	// Some data to test on
	int data; 

	// OK, we can have a plain incomplete type if it is static
	static Foo static_mem;

	// With non-static data members, we can only have a pointer or a reference to an incomplete type
	Foo* ptr_mem;
	Foo& ref_mem = *ptr_mem;

	// error: field ‘plain_mem’ has incomplete type ‘Foo’
	// Foo plain_mem;

	Foo(int i = 21, Foo* foo_ptr = nullptr) : data(i), ptr_mem(foo_ptr) {}
};

// Global variable to be passed to the static data member of the Foo class
Foo absolute_foo(1);
// Initialize the static member 
Foo Foo::static_mem = Foo(42, &absolute_foo);


// Another unusual use.
// We can use a static data mem as a defatult argument.
class Bar 
{
	int data;
	static const int default_data = 63;
public:
	Bar(int data_init = default_data) : data(data_init) {}
};


// Lets try both uses combined:

class Baz
{
	int data;
	static Baz default_baz;
public:
	// Test funciton with the default argument of the same class type
	void func(const Baz& baz = default_baz) 
	{ 
		std::cout << "Baz::func is called\nbaz.data: " << baz.data << std::endl; 
	}
	
	Baz(int i) : data(i) {}
	Baz() = delete;
};
// Provide the value for the default baz
Baz Baz::default_baz = Baz(84);

int main() 
{
	// Will have the default value for the data, 21
	Foo foo_1;
	
	// Supply the value for the data, 42
	// Supply reference to another Foo
	Foo foo_2(42, &foo_1);
	
	// Prints 21
	std::cout << foo_2.ref_mem.data << std::endl;

	// Prints 42
	std::cout << foo_2.static_mem.data << std::endl;

	// Prints 42
	std::cout << foo_2.ref_mem.static_mem.data << std::endl;

	// Funny(?)
	// Prints 42
	std::cout << foo_1.static_mem.static_mem.static_mem.static_mem.static_mem.static_mem.static_mem.data << std::endl;

	// Prints 1
	std::cout << foo_1.static_mem.ref_mem.data << std::endl;

	// Prints 42
	std::cout << foo_1.static_mem.ref_mem.static_mem.ref_mem.static_mem.data << std::endl;

	// Call to func will utilize both of the static member privileges
	Baz baz(105);
	baz.func();
}

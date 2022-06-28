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
Foo Foo::static_mem = Foo(63);


// And another unusual use.
// We can use a static data mem as a defatult argument.
class Bar 
{
	int data;
	static const int default_data = 84;
public:
	Bar(int data_init = default_data) : data(data_init) {}
};


int main() 
{
	Foo foo_1;
	Foo foo_2(42, &foo_1);
	std::cout << foo_2.ref_mem.data << std::endl;
	std::cout << foo_2.static_mem.data << std::endl;

}

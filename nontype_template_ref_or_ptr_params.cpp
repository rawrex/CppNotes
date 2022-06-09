#include <iostream>

// Arguments bound to a ponter or reference nontype parameter must have static lifetime
// We cannot use non-static local object or a dynamic object as a template argument

template <int* int_ptr>
void print_ptr()
{
	for(auto i = n; i!=0; --i)
		std::cout << *int_ptr << ' ';
	std::cout << std::endl;
}

int main()
{
	int i = 42;
	static int si = 21;
	static int* pi = &i;

	// ok
	print_ptr<&si>();

	// error: the address of ‘i’ is not a valid template argument
	// because it does not have static storage duration
	print_ptr<&i>();

	// error: ‘pi’ is not a valid template argument because ‘pi’ is a variable,
	// not the address of a variable
	print_ptr<pi>();
}

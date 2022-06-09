#include <iostream>

double arr[3] = {3.14, 1.16, 4.12};

// Standard form, explicit
double (*foo(int i))[3] 
{
	return &arr;
}

// Using trailing return
auto bar(int i) -> double(*)[3]
{
	return &arr;
}

// Using decltype with pointer type specifier
decltype(arr)* baz(int i)
{
	return &arr;
}

int main() {

	// N.B.
	// Subscript has higher precedence than the dereference
	// subscript past the pointer to arr and then dereference the address
	// std::cout << *foo(1)[2] << std::endl;		

	std::cout << (*foo(1))[2] << std::endl;	
	std::cout << (*bar(1))[2] << std::endl;	
	std::cout << (*baz(1))[2] << std::endl;	

}

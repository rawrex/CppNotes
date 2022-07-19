#include <iostream>
#include <typeinfo>


int main() {
	int i = 21;
	int* pint = &i;

	// The unary plus operator and the addition and subtraction operators may also be applied to pointers.
	// When applied to a pointer or arithmetic value, unary plus returns a (possibly promoted)
	// copy of the value of its operand.
	// The unary minus returns (possibly promoted) copy of the negated value of its operand.

	// -pint; // error: wrong type argument to unary minus
	+pint; // ok

	std::cout<< typeid(+pint).name() <<std::endl;
	std::cout<< typeid(pint).name() <<std::endl;
}

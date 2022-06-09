#include <iostream>
#include <typeinfo>


int main() {
	int i = 21;
	int* pi = &i;

	-pi; // error: wrong type argument to unary minus
	+pi; // ok

	std::cout<< typeid(+pi).name() <<std::endl;
	std::cout<< typeid(pi).name() <<std::endl;
}

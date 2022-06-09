#include <iostream>

int & foo()
{
	static int i; // value initialized
	return ++i;
}
int*& bar()
{
	static int i; // value initialized
	static int* pi = &i;
	++i;
	return pi;
}

int main() {

	std::cout << foo() << std::endl;	
	std::cout << foo() << std::endl;	
	std::cout << foo() << std::endl;	
	
	std::cout << *bar() << std::endl;	
	std::cout << *bar() << std::endl;	
	std::cout << *bar() << std::endl;	

}

#include <iostream>

void print(char c) 
{
	std::cout << "char: " << c << std::endl;
}
void print(long double d) 
{
	std::cout << "double: " << d << std::endl;
}
void printSize(void * ptr)
{
	std::cout << "sizeof(): " << sizeof(ptr) << std::endl; 	
}

int main() {

	// A void pointer can be used to point to any type
	void * vp = nullptr;
	char c = 'x';
	long double d = 3.1415;
	
	// Later we can use that pointer only after casting it to a proper type
	vp = &c;
	print(* static_cast<char *>(vp));
	vp = &d;
	print(* static_cast<long double *>(vp));

	std::cout << sizeof(static_cast<char*>(vp) + 1000) << std::endl;
}

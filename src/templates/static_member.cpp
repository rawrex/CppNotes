#include <iostream>
#include <string>

template <typename Type, size_t N = 21>
class MyClass
{
public:
	const static int i = 5;
	static Type j;
};

template <typename T, size_t N>
T MyClass<T, N>::j = "foo";

int main() 
{
	MyClass<double> foo;
	std::cout << foo.i << std::endl;
	std::cout << MyClass<double>::i << std::endl;

	std::cout << MyClass<std::string>::j << std::endl;
}

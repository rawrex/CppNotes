#include <iostream>
#include <string>
#include <utility>
#include <vector>


struct Foo
{
    int a = 0;
    std::string b;
};


int main() {

	Foo foo = {21, "foobar"};
	std::cout << foo.a << ' ' << foo.b << std::endl;

	// If you break in a debugger, it shows that there are two local variables
	// int x and string y created. 
	// x and y are called structural bindings.
	auto [x, y] = foo;
	std::cout << x << ' ' << y << std::endl;


	// std::pair example
	std::vector<std::pair<std::string, std::string>> vec = {{"foo","bar"}, {"baz","qux"}};

	for (const auto [a, b] : vec)
		std::cout << a << ", " << b << std::endl;

}


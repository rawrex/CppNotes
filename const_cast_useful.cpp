#include <iostream>
#include <string>

const std::string& foo(const std::string& s)
{
	std::cout << "const string foo()" << std::endl;
	return s;
}
std::string& foo(std::string& s)
{
	std::cout << "string foo()" << std::endl;
	// Infinite recursion case:
	// return const_cast<std::string&>(foo(s));
	return const_cast<std::string&>(foo(const_cast<const std::string&>(s)));
}


int main() {

	std::string s1 = "foo";
	const std::string s2 = "bar";
		
	foo(s1);
	foo(s2);

}

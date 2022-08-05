#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print(const T& container)
{
	for(const auto& elem : container)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

int main() {

	std::vector<const char*> vec = {"foo", "bar", "baz"};
	std::list<std::string> lt(vec.cbegin(), vec.cend());
	print(lt);
	
}

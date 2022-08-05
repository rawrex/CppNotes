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
	
	// The ctor takes two iterators denoting a range of elements
	// In such construction, there's no requirements for the types of containers
	// Or types of their elements to match (they just have to be convertable).
	std::list<std::string> lt(vec.cbegin(), vec.cend());
	print(lt);
	
}

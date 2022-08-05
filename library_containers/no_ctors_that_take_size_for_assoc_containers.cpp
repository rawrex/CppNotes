#include <iostream>
#include <map>

int main() {

	std::map<std::string, std::size_t> cont1{{"foo", 21}};
	std::map<std::string, std::size_t> cont2{std::pair<std::string, std::size_t>{"foo", 21}};

	// Ctors that take a size are valid only for sequential containers
	// And they are not supported for the associative containers
	//
	// std::map<std::string, std::size_t> cont(100);
	// std::map<std::string, std::size_t> cont3(10, std::pair<std::string, std::size_t>{"foo", 21});

}

#include <iostream>
#include <map>
#include <utility>

int main() {
	std::map<std::pair<size_t, size_t>, const std::string> m { {{11, 12}, "foo"}, {{21, 22}, "bar"}  };
	// const std::pair<size_t, size_t> p(11,12);
	
	std::cout << m[{11,12}] << std::endl;
	
}

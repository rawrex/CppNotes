#include <iostream>
#include <vector>
#include <string>

template <typename T>
using DoubleVec = std::vector<std::vector<T>>;

int main() {
	DoubleVec<std::string> vec(4, {"foo", "bar", "baz"});
	for (const auto & v : vec)
		for (const auto & str : v)
			std::cout << str << std::endl;
}

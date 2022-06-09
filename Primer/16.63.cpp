#include <iostream>
#include <cstring>
#include <string>
#include <vector>

template <typename T, typename X>
unsigned count(const T& cont, const X& val) {
	unsigned ret = 0;
	for (auto i : cont)
		if(i == val) ++ret;
	return ret;
}

template <>
unsigned count(const std::vector<const char*>& cont, const char* const& val) {
	unsigned ret = 0;
	for (auto i : cont) {
		std::cout << i << ' ';
		if(0 == strcmp(val, i)) ++ret;
	}
	return ret;
	
}
int main() {
	std::vector<int> vi {1,2,3,4,2};
	std::vector<std::string> vs {"foo", "bar", "baz", "foo"};
	std::vector<double> vd {1,2,3.14,4,5,6,3.14};

	//std::cout << count(vi, 2) << std::endl;
	//std::cout << count(vs, "foo") << std::endl;
	//std::cout << count(vd, 3.14) << std::endl;

	std::vector<const char*> vcc = { "alan", "alan", "alan", "alan", "moophy" };
	std::cout << count(vcc, "alan") << std::endl;
}

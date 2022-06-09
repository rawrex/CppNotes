// Ex 16.19

#include <vector>
#include <string>
#include <iostream>

template <typename T> std::ostream& print(const T& cont, std::ostream& os = std::cout) {
	typename T::size_type b = 0, e = cont.size();
	for (; b < e; ++b)
		os << cont[b] << ' ';
	return os;
}
template <typename T> std::ostream& printit(const T& cont, std::ostream& os = std::cout) {
	typename T::const_iterator b = cont.cbegin(), e = cont.cend();
	for (; b != e; ++b)
		os << *b << ' ';
	return os;
}

int main () {
	std::vector<double> vec {3.14, 1.61, 1.18};
	std::string str {'f','o','o'};
	printit(vec) << std::endl;
}

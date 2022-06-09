#include <iostream>


// Ex 16.53
template <typename T> std::ostream& print(std::ostream& os, const T& t) {
	return os << t;
}
template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest) {
	os << t << ", ";
	return print(os, rest...);
}


// Ex 16.54
struct Foo {
};


// Ex 16.56
template <typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args&... rest) {
	return print(os, rest...);
}

int main () {
	int i = 21;
	errorMsg(std::cout, "foo", 3.14, i, 'c') << std::endl;	
}

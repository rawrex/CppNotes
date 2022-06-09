#include <iostream>
#include <memory>
#include <string>

template <typename It>
auto compare (It a, It b) -> decltype(*a + 0) {}

template <typename T, typename X>
auto sum(T a, X b) -> decltype(a+b) {
	return a+b;
}
int main() {
	std::cout << sum(1, 3.1415) << std::endl;
}

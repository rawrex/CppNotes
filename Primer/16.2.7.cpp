#include <utility>
#include <iostream>

template <typename F, typename T1, typename T2>
auto flip(F f, T1&& a, T2&& b) -> decltype(f(std::forward<T2>(b),std::forward<T1>(a))) {
	return f(std::forward<T2>(b), std::forward<T1>(a));
}

int foo(int a, int& b) { ++a; ++b; return a+b; }
int bar(int a, int&& b) { ++a; ++b; return a+b; }
int baz(int& a, int&& b) { ++a; ++b; return a+b; }

int main() {
	int i = 3;
	std::cout << flip(bar, 33, i) << " i: " << i << " 33" << std::endl;
}

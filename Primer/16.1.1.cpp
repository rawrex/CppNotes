#include <iostream>
#include <string>
#include <vector>
#include <list>


// Ex 16.4
template <typename IterType, typename ValType>
IterType find(IterType&& b, IterType&& e, const ValType& val) {
	for (; b != e && *b != val; ++b);
	return b;
}
template <typename IterType, typename ValType>
IterType find(IterType& b, IterType& e, const ValType& val) {
	for (; b != e && *b != val; ++b);
	return b;
}

// Ex 16.5
template <typename T, std::size_t Size>
void print(const T (&word)[Size]) {
	for (std::size_t i = 0; i != Size; ++i)
		std::cout << word[i];
	std::cout << std::endl;
}

// Ex 16.6
template <typename T, std::size_t Size>
T* beg(T (&foo)[Size]) {
		return &(foo[0]);
}
template <typename T, std::size_t Size>
T* end(T (&foo)[Size]) {
		return &(foo[Size]);
}

// Ex 16.7
template <typename T, std::size_t S>
constexpr std::size_t size(const T (&arr)[S]) {
	return S;
}

// Ex 16.8
int main() {
	int arr[] = {1,3,3,7};
	for (auto b = beg(arr); b < end(arr); ++b)
		std::cout << *b << ' ';
	std::cout << std::endl;
}

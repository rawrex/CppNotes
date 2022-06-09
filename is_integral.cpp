#include <string>
#include <iostream>
#include <chrono>
#include <set>
#include <utility>
#include <type_traits>

std::multiset<std::string> names;


// Get a name by an index
std::string nameFromIdx(int idx) { return std::string(); }

template<typename T>
void logAndAddImpl(T&& name, std::false_type);

template<typename T>
void logAndAdd(T&& name)
{
	logAndAddImpl(
		std::forward<T>(name),
		// Tell whether the T is integral 
		// (need to remove any lvalue references due to universal reference presence)
		std::is_integral<typename std::remove_reference<T>::type>()
		// or std::remove_reference_t<T> in C++14
	);
}

// Boolean true and false are runtime values,
// and we need to use overload resolution - a compile-time phenomenon
// we need TYPES that corresponds to true and false

// The T is not an integral type 
template<typename T>
void logAndAddImpl(T&& name, std::false_type)
{
	// auto now = std::chrono::system_clock::now();
	// log(now, "logAndAdd");
	std::cout << "logAndAdd" << std::endl;
	names.emplace(std::forward<T>(name));
}

// The T is an integral type
// We avoid rewrtiting logging code by directing the fetched name to the first overload
void logAndAddImpl(int idx, std::true_type)
{
	logAndAdd(nameFromIdx(idx));
}

int main() {

}

#include <iostream>

// Functions can’t declare parameters that are truly arrays,
// but they can declare parameters that are references to arrays!
template<typename T>
void f(T& param);

// The ability to declare references to arrays enables creation of a template
// that deduces the number of elements that an array contains:
template <typename T, std::size_t Size>
constexpr std::size_t size(T(&)[Size]) noexcept
{
	return Size;
}

int main() {

	// Our test array of six+one const characters	
	const char foo[] = "foobar";

	// Here, the type deduced for T is the actual type of the array!
	// That type includes the size of the array
	f(foo);	

	int arr[] = {1,2,3,4,5};
	std::cout << size(arr) << std::endl;

}

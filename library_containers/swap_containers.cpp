#include <iostream>
#include <vector>
#include <array>
#include <list>

template <typename T>
void print(const T& msg)
{
	std::cout << msg << std::endl;
}
template <typename Msg, typename T>
void print(const Msg& msg, const T& a, const T& b)
{
	std::cout << msg << ":\t" << a << ' ' << b << std::endl;
}


// In a swap operation the elements themselves are not copied or moved,
// only internal structures are changed.
// So, swap on all types (except std::array) is guaranteed to be a constant time operation.
//
// Note, however, swapping two arrays does exchange their elements,
// so swap on arrays grows proportionally to their sizes.

void swap_diff_types_fail()
{
	std::list<int> lt{1,2,3,4,5};
	std::vector<int> vec{11,22,33,44,55};

	// error: cannot convert ‘std::__cxx11::list<int>’ to ‘std::vector<int>&’
	// vec.swap(lt);
}
void swap_iterators_not_invalidate()
{
	std::vector<int> vec1{1,2,3,4,5};
	std::vector<int> vec2{11,22,33,44,55};

	// Note, the iterators (references, pointers) won't be invalidated
	// They will refer to the same elements as before
	// Only that these elements will be in a different container

	auto iter_1 = vec1.cbegin();				// referes to an element in vec1, with value 1
	auto iter_2 = vec2.cbegin();				// referes to an element in vec2, with value 11

	vec1.swap(vec2);
	
	// now iter_1 should refer to an element with the same value 1
	// only in the different container, the vec2
	print("Swaped places, iter1 and vec2.cbegin()", *iter_1, *vec2.cbegin());

	// now iter_2 should refer to an element with the same value 11
	// only in the different container, the vec1
	print("Swaped places, iter2 and vec1.cbegin()", *iter_2, *vec1.cbegin());

	// Note, the call to swap() on a std::string may invalidate iterators, references and pointers.
}
void swap_array_example()
{
	std::array<int, 4> arr_1 {1,2,3,4};
	std::array<int, 4> arr_2 {11,22,33,44};

	auto& reference_1 = arr_1[0];
	auto& reference_2 = arr_2[0];

	auto* pointer_1 = &arr_1[0];
	auto* pointer_2 = &arr_2[0];

	auto iterator_1 = arr_1.cbegin();
	auto iterator_2 = arr_2.cbegin();

	print("\nBefore swap");
	print("References", reference_1, reference_2);
	print("Pointers", *pointer_1, *pointer_2);
	print("Iterators", *iterator_1, *iterator_2);

	std::swap(arr_1, arr_2);

	print("\nAfter swap");
	print("References", reference_1, reference_2);
	print("Pointers", *pointer_1, *pointer_2);
	print("Iterators", *iterator_1, *iterator_2);
}

	
int main() {
	// swap_diff_types_fail();
	swap_iterators_not_invalidate();
	swap_array_example();
}

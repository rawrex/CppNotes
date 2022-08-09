#include <iostream>
#include <vector>
#include <list>


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

	std::cout << *iter_1 << std::endl;			// now should refer to an element with the same value 1
	std::cout << *vec2.cbegin() << std::endl;	// only in the different container, the vec2

	std::cout << *iter_2 << std::endl;			// now should refer to an element with the same value 11
	std::cout << *vec1.cbegin() << std::endl;	// only in the different container, the vec1
}

	
int main() {
	// swap_diff_types_fail();
	swap_iterators_not_invalidate();
}

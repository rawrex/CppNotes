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
void swap_iterators_invalidate()
{
	std::vector<int> vec1{1,2,3,4,5};
	std::vector<int> vec2{11,22,33,44,55};

	// Note, the iterators will be invalidated
	auto beg = vec1.cbegin(), end = vec1.cend();

	vec1.swap(vec2);
}

	
int main() {
	// swap_diff_types_fail();
	swap_iterators_invalidate();
}

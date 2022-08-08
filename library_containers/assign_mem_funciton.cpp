#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print(const T& cont)
{
	for(const auto& elem : cont)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

void assign_same_size_diff_types_example()
{
	std::vector<int> vec{1,2,3};
	std::list<int> lt{11,22,33};
	
	// error: no match for ‘operator=’ 
	// vec = lt;

	vec.assign(lt.cbegin(), lt.cend());
	print(vec);
}

void assign_diff_size_diff_types_example()
{
	std::vector<int> vec{1,2,3};
	std::list<int> lt{11,22,33,44};
	
	vec.assign(lt.cbegin(), lt.cend());
	print(vec);
}
void assign_refers_to_itself()
{
	std::vector<int> vec{1,2,3};

	// Note, since the existing elements are replaced
	// The arguments to assign must not refer to the cont. on which assign is called
	auto beg = vec.cbegin(), end = vec.cend();
	vec.assign(beg, end);

	print(vec);
}
void assign_takes_integral_value_and_elem_value_example()
{
	std::vector<int> vec{1,2,3};

	vec.assign(5, -1);
	print(vec);
}


int main() {
	assign_same_size_diff_types_example();
	assign_diff_size_diff_types_example();
	assign_refers_to_itself();
	assign_takes_integral_value_and_elem_value_example();
}


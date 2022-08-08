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

int main() {
	assign_same_size_diff_types_example();
	assign_diff_size_diff_types_example();
}


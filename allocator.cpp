#include <iostream>
#include <memory>
#include <string>


template <typename T, size_t StackSize>
class StaticVector
{
public:
	template <typename... Args>
	StaticVector(size_t size, Args&&... args) 
		: current_stack_size(size < StackSize ? size : StackSize)
	{
		// if size > StackSize we need to allocate dynamic memory

		for (size_t i=0; i!= size; ++i)
			new (stack_data+i) T(std::forward<Args>(args)...);	
	}

	T& operator[](size_t index)
	{
		if(index > StackSize)
			return dynamic_data[index-StackSize];
		else
			return stack_data[index];
	}
	

private:
	// Data members
	std::allocator<T> allocator;

	T stack_data[StackSize];

	size_t current_stack_size;

	T* dynamic_data;
	size_t current_dynamic_size;
	
};

int main() {

	StaticVector<std::string, 3> svec(2, 10, 'x');
	std::cout << svec[0] << std::endl;
	std::cout << svec[1] << std::endl;
	
}

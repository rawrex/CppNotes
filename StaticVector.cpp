#include <iostream>
#include <memory>
#include <string>


template <typename T, size_t StackSize>
class StaticVector
{
public:
	template <typename... Args>
	StaticVector(size_t size, Args&&... args) : 
		elements_count(size)
	{
		if(size > StackSize)
			allocate();	

		for (size_t i=0; i!= size; ++i)
			new (stack_data+i) T(std::forward<Args>(args)...);	
	}

	void push_back(const T& item)
	{
		if(++elements_count<StackSize);
	}

	T& operator[](size_t index)
	{
		if(index <= StackSize)
			return stack_data[index];
		else
			return dynamic_data[index-StackSize];
	}
	
private:
	void allocate()
	{
		//dynamic_data = allocator.allocate(elements_count*2);
	}

private:
	// Data members
	std::allocator<T> allocator;

	T stack_data[StackSize];

	// Do we really need to track the stack portion explicitly
	// Or can we just track if the general elements count is under the StackSize
	size_t current_stack_size = 0;
	size_t elements_count = 0;

	T* dynamic_data = nullptr;
	size_t current_dynamic_size = 0;
	
};

int main() {

	StaticVector<std::string, 3> svec(2, 10, 'x');
	std::cout << svec[0] << std::endl;
	std::cout << svec[1] << std::endl;
	
}

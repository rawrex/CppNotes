#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	auto adder_generator = [](int a)
	{
		int data_member = a;

		// If the capture were by reference,
		// then the data member is having indeterminate values
		// return [&data_member](int j)
		return [data_member](int j)
		{
			return j + data_member;
		};
	};

	auto adder = adder_generator(10);
	auto result = adder(3);

	std::cout << result << std::endl;
}

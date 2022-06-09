#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using std::placeholders::_1;

int main() {
	std::vector<int> vec {123, 1234, 12345, 123456};
	std::cout <<
		std::count_if(vec.begin(), vec.end(), std::bind(std::less<int>(), _1, 1024))
	<< std::endl;

	std::vector<std::string> vecs {"pooh", "pooh", "bar"};
	std::cout <<
		*std::find_if(vecs.begin(), vecs.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"))
	<< std::endl;

	std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), _1, 3));
	for (auto i : vec)
			std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "Start new" << std::endl;
	std::vector<unsigned> nums {1,2,3,4,5,6,7,8,9};
	std::vector<int> out;
	unsigned n = 10;
	std::copy_if(nums.cbegin(), nums.cend(), std::back_inserter(out), 
					[n](unsigned i){ return !(n%i); });

//	for (auto i : out)
//		std::cout << i << " ";
//	std::cout << std::endl;


}

#include <iostream>
#include <random>


void legacyExample()
{
	std::cout << "\nLegacy example:" << std::endl;

	// Seeds the pseudo-random number generator used by rand()
	// Here, we use the current system time
	srand(time(nullptr));

	// Returns a pseudo-random integer value between ​0​ and RAND_MAX (inclusively)
	auto random_number = rand();
	std::cout << random_number << std::endl;
}

void basicExample()
{
	std::cout << "\nBasic example:" << std::endl;
	std::default_random_engine engine(time(nullptr));
	std::cout << engine() << std::endl;
}



int main()
{
	legacyExample();
	basicExample();
}

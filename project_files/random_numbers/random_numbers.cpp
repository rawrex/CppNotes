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
	
	// Seed the current time as well
	std::default_random_engine engine(time(nullptr));

	// Unsigned integral type that the engine generates
	std::default_random_engine::result_type random_number = engine();
	std::cout << random_number << std::endl;

	std::cout << "The smallest value: " << engine.min() << "; The largest value: " << engine.max() << std::endl;
}



int main()
{
	legacyExample();
	basicExample();
}

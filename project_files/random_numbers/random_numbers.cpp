#include <iostream>
#include <random>


void legacyExample()
{
	// Seeds the pseudo-random number generator used by rand()
	// Here, we use the current system time
	srand(time(nullptr));

	// Returns a pseudo-random integer value between ​0​ and RAND_MAX (inclusively)
	auto random_number = rand();
	std::cout << random_number << std::endl;
}



int main()
{
	legacyExample();
}

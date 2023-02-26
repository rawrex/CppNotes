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
	// We can use any other integral value, even a fixed one (e.g. to aid testing)
	std::default_random_engine engine(time(nullptr));

	// Unsigned integral type that the engine generates
	std::default_random_engine::result_type random_number = engine();
	std::cout << random_number << std::endl;

	std::cout << 
		"The smallest value: " << engine.min() << 
		"; The largest value: " << engine.max() 
	<< std::endl;

	// Advance the engine by three steps
	engine.discard(3);
}

void distributionExample()
{
	std::cout << "\nDistribution example:" << std::endl;
	
	// A given generator returns the same sqeunce of number each time (with the same seed of course)
	// So, we have to declare both the engine and the distribution as static
	static std::uniform_int_distribution<> distribution(0, 9);	// Inclusive ranges
	static std::default_random_engine engine(time(nullptr));

	// A "random number generator" is the two entities combined
	std::default_random_engine::result_type random_number = distribution(engine);
	std::cout << random_number << std::endl;

	std::cout << 
		"The smallest distribution value: " << distribution.min() << 
		"; The largest distribution value: " << distribution.max() 
	<< std::endl;

	// Reistablish the state of the distribution
	// Subsequent calls has no dependence on the values the distribution has already generated
	distribution.reset();
	std::cout << distribution(engine) << std::endl;
}

void realDistributionExample()
{
	std::cout << "\nReal distribution example:" << std::endl;

	static std::default_random_engine engine(time(nullptr));
	static std::uniform_real_distribution<> real_distribution;

	std::cout << real_distribution(engine) << std::endl;
}

int main()
{
	legacyExample();
	basicExample();
	distributionExample();
	realDistributionExample();
}

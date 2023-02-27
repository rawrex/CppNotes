#include "condition_states_examples.h"
#include <iostream>
#include "utils/utils.h"

void test_cin() 
{
	if(std::cin.eof())
		IOLibrary::print("eofbit is on");	
	if(std::cin.fail())
		IOLibrary::print("failbit is on");	
	if(std::cin.good())
		IOLibrary::print("good");	
}

void basic_set_clear_test()
{
	std::cin.setstate(std::cin.eofbit);
	std::cin.setstate(std::cin.failbit);

	// Clear, leaving only the eofbit set
	IOLibrary::print("Set the eofbit and failbit:");
	test_cin();
	
	// Clear, leaving only the eofbit set
	std::cin.clear(std::cin.rdstate() & std::cin.eofbit);
	IOLibrary::print("\nCleared the failbit, left the eofbit in place:");
	test_cin();

	// Resets to the current values, useless
	std::cin.clear(std::cin.rdstate());
	IOLibrary::print("\nCleared nothing. Resets to current values:");
	test_cin();

	// Clear all
	std::cin.clear();
	IOLibrary::print("\nCleared all:");
	test_cin();
}

void condition_states_examples_main() 
{
	basic_set_clear_test();
}

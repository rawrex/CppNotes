#include <iostream>

void print(const std::string & msg) { std::cout << msg << std::endl; }
void test_cin() 
{
	if(std::cin.eof())
		print("eofbit is on");	
	if(std::cin.fail())
		print("failbit is on");	
	if(std::cin.good())
		print("good");	
}

int main() {

	std::cin.setstate(std::cin.eofbit);
	std::cin.setstate(std::cin.failbit);
	// Clear, leaving only the eofbit set
	print("Set the eofbit and failbit:");
	test_cin();
	
	// Clear, leaving only the eofbit set
	std::cin.clear(std::cin.rdstate() & std::cin.eofbit);
	print("\nCleared the failbit, left the eofbit in place:");
	test_cin();

	// Resets to the current values, useless
	std::cin.clear(std::cin.rdstate());
	print("\nCleared nothing. Resets to current values:");
	test_cin();

	// Clear all
	std::cin.clear();
	print("\nCleared all:");
	test_cin();
}

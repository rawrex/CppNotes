#include <stdexcept>
#include <iostream>

void print(std::string msg) 
{ 
	std::cout << msg << std::endl; 
}

int main() {

	try {
		throw std::runtime_error("Run time error!");
	}
	catch (const std::runtime_error& rte) {
		print(rte.what());
	}
	
	print("Regular execution continues.");
}

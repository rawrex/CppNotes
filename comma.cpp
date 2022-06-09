#include <iostream>

int one() 
{ 
	std::cout << "one()" << std::endl;
	return 1; 
}
int two() 
{ 
	std::cout << "two()" << std::endl;
	return 2; 
}
int three() 
{ 
	std::cout << "three()" << std::endl;
	return 3; 
}

// Operator "," is nothing else than a separator of sequential expressions in C,
// in expression programming it serves the same role as ; does in statement programming.
// Branching in expression programming is done through ?: operator and, alternatively,
// through short-circuit evaluation properties of && and || operators.
// (Expression programming has no cycles though)

int main() {

	std::cout << (one(), two(), three()) << std::endl;
	
}

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>


int main () {

	int i = 42;

	// An array of ints
	int arr[1] = {21};

	// Pointer to the first elem of the array
	int* pi = arr;

	// Pointer to an array[1] of ints
	int (*parr)[1] = &arr;

	// The types of the parr and the arr are different...

	std::cout << "parr: " << typeid(parr).name()
	<< ' ' << "arr: " << typeid(arr).name() << std::endl;

	// ...Thought they do have the same value
	// Test, dereference the pointer and subscript the array:
	std::cout << (*parr)[0] << std::endl;
	// Test, deref the pointer and deref the array:
	std::cout << **parr << std::endl;
	// Test, subscript the pointer and subscript the array:
	std::cout << parr[0][0] << std::endl;

	// Note, when we subscript an array, we're really subscripting a pointer
	// to the first element in that array.

	// An array of pointers to ints
	int *arrp[2] = {&i, pi};

	// Reference to a pointer to int
	int *&rp = pi;

	// A reference to an array
	int (&rarr)[1] = arr;	

	// A reference to an array of pointers to int
	int* (&rarrp)[2] = arrp;
}

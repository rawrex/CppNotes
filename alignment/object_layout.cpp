#include <iostream>

// Nonstatic data members of a (non-union) class with the same access control 
// are allocated so that later members have higher addresses within a class object.
//
// The order of allocation of non-static data members with different access control is unspecified.
//
// Implementation alignment requirements might cause two adjacent members 
// not to be allocated immediately after each other 
// (due to padding, see ./general_info_on_data_alignment.cpp);
// so might requirements for space for managing virtual functions and virtual base classes.


// So, memory layout is mostly left to the implementation.
// The key exception is that member variables for a given access specifier 
// will be in order of their declaration.

int main() {

}

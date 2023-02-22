#include <iostream>
#include <type_traits>

int main() {
	int i(42);
	int * const pic(&i);

	// Error: inconsistent deduction for ‘auto’: ‘int* const’ and then ‘int*’
	// auto & foo(pic), bar(pic);

	// This won't work, since top-level const of the pic wasn't igonred in deduction
	// foo = &j;
}

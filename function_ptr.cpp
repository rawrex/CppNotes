#include <iostream>

// Auxilary printer function
void print(const std::string& msg, int i = 0) 
{ 
	std::cout << msg;
	if (i) std::cout << ' ' << i;
	std::cout << std::endl; 
}

// Test function
void foo(int i) 
{
	print("foo(i)", i); 
} 

// Function type alias
using foo_t = void(int);
// Function pointer type alias
using foo_ptr_t = void(*)(int);


// A function type as a PARAMETER type 
// is automatically treated as a pointer type

// Here, explicitly state that the f is a pointer to function
void bar(void (*f)(int), int i);

// Equivalent, f is automatically treated as a pointer to the foo_t
void bar(void f(int), int i);

// Equivalent, f is automatically treated as a pointer to the type of the foo
void bar(decltype(foo) f, int i);

// Equivalent, f is an explicit pointer to the type of the foo function
void bar(decltype(foo)* f, int i);

// Equivalent, explicit pointer to a function type alias
void bar(foo_t* f, int i);

// Equivalent, function type alias implicitly treated as a pointer to function type
void bar(foo_t f, int i);

// Equivalent, function pointer type alias
void bar(foo_ptr_t f, int i);

// Definition
void bar(void (*f)(int), int i) 
{
	print("foo(foo_t)", i); 
	f(i+10);
}



// A function type as a RETURN type 
// won't be automatically treated as a pointer to funciton type

// Here, baz is a function that doesn't take agruments
// And returns a pointer to a function that takes an int argument and "returns" void
void (*baz())(int);

// No pointer specification
// error: ‘baz’ declared as function returning a function
// void baz()(int);

// Equivalent, return type is a pointer to the type of foo
decltype(foo)* baz();

// No pointer specification
// error: ‘baz’ declared as function returning a function
// decltype(foo) baz();

// Trailing return explicit type specification
auto baz() -> void(*)(int);

// Deduce the return type from the type of pointer to the type of foo
auto baz() -> decltype(foo)*;

// Equivalent, returns a pointer to the function type alias
foo_t* baz();

// Equivalent, returns a function pointer type alias
foo_ptr_t baz();

// Definition
void (*baz())(int)
{
	return foo;
}


int main() {

	// A regular function pointer

	// Explicit type specification:
	void(*fp1)(int) = foo;

	// Using decltype, note the explicit pointer type specifier
	// Also, cannot be used on an overloaded functions set.
	decltype(foo)* fp2 = foo;

	// Using function type alias:
	foo_t* fp3 = foo;

	// Using function pointer type alias:
	foo_ptr_t fp4 = foo;

	// Using auto
	auto fp5 = foo;

	// Usage for all of the above function pointers
	fp1(111);
	fp2(222);
	fp3(333);
	fp4(444);
	fp5(555);

}

#include <iostream>

void print(const std::string& str) { std::cout << str << std::endl; }

struct Foo {};

void printFoo(const Foo & foo) { print("const &"); }
void printFoo(Foo && foo) { print("&&"); }

bool test_a(bool b)
{
	print("test_a()");
	return b;
}
bool test_b(bool b)
{
	print("test_b()");
	return b;
}
void a() 
{
	print("a");
}
void b() 
{
	print("b");
}
void c() 
{
	print("c");
}

int main() {

	const bool flag = true;	
	Foo foo;
	
	// The operands to the ternary operator must be of the same type
	// Or must be convertable to a commmon type.
	// error: operands to ?: have different types ‘int’ and ‘Foo’
	// printFoo(flag ? int() : foo);
	
	// The result of the cond.operator is an lvalue if both expressions are lvalues
	// (or can convert to a common lvalue type); otherwise, the result is an rvalue

	printFoo(flag ? foo : foo);			// lvalue
	printFoo(flag ? Foo() : foo);		// rvalue
	printFoo(flag ? foo : Foo());		// rvalue
	printFoo(flag ? Foo() : Foo());		// rvalue

	std::cout << std::endl;
	// Prints: test_a(), test_b(), c
	(test_a(false)) ? a() : (test_b(false)) ? b() : c();
	
}

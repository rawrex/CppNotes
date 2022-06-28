#include <iostream>

struct Foo {

	// All good
	const static bool b = true;
	const static size_t size = 42;
	const static unsigned uint = 63;
	const static char ch = 84;
	const static long ln = 105;
	const static long long lnln = 126;
	const static wchar_t wch = 147;

	// Failing member
	const static int integer = 21;

};

// If we do supply the outside definition, looking in the object file will show us
// That Foo::integer is in a read only data seciton: "R Foo::integer"
// const int Foo::integer; 

// Same for any other data member of the Foo class
// const unsigned Foo::uint; 

// But if we do not supply outside definition for the Foo::integer
// We'll get: "U Foo::integer". Which means that the member is not defined.
// While we do not get the same status for any other data member in Foo


// The test context for a member to be used where it won't be a simple substitution of the value
void print(const int& i) { std::cout << "print(" << i << ')' << std::endl; }

int main() {
	
	// These are OK:
	print(Foo::b);
	print(Foo::size);
	print(Foo::uint);
	print(Foo::ch);
	print(Foo::ln);
	print(Foo::lnln);
	print(Foo::wch);

	// undefined reference to `Foo::integer'
	print(Foo::integer);
}


// Related threads:
// https://stackoverflow.com/questions/5391973/undefined-reference-to-static-const-int
// https://stackoverflow.com/questions/272900/undefined-reference-to-static-class-member
// https://stackoverflow.com/questions/5508182/static-const-int-causes-linking-error-undefined-reference

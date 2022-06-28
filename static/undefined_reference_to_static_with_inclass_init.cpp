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

// The test context for a member to be used where it won't be a simple substitution of the value
void print(const int& i) { std::cout << "print(" << i << ')' << std::endl; }

int main() {
	// These are OK due to the implicit conversions and introduced temporaries as a result.
	// So, none of these calls tries to fetch the address of an undefined statis data member
	print(Foo::b);
	print(Foo::size);
	print(Foo::uint);
	print(Foo::ch);
	print(Foo::ln);
	print(Foo::lnln);
	print(Foo::wch);

	// undefined reference to `Foo::integer'
	// Since we pass the exact type, so no conversions, no temporaries{
	print(Foo::integer);

	// We can "avoid" this linkage error even in this case if we explicitly make a temporary
	print(static_cast<int>(Foo::integer));
	// Or like so
	print(+Foo::integer);
}

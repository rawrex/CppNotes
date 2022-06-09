#include <iostream>
#include <cstring>
#include <string>

struct Foo 
{
	Foo() = default;
	Foo(int x, int y) : a(x), b(y) {}
	int a;
private:
	int b;
};

int main() 
{
	Foo f1 {21, 3};
	Foo f2;
	unsigned char arr[10];

	std::memcpy(&arr, &f1, sizeof(Foo));
	std::memcpy(&f2, arr, sizeof(Foo));

	std::cout << f2.a << std::endl;
}

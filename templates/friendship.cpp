#include <iostream>

template <typename T>
class Foo
{
	
};

template <typename T>
class Bar;

template <typename T>
bool operator==(const Bar<T>&, const Bar<T>&);

template <typename T>
class Bar
{
	friend class Foo<T>;
	friend bool operator==<T>(const Bar<T>&, const Bar<T>&);
};

int main() {

}

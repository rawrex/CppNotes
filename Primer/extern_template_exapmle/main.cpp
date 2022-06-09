#include <iostream>
#include "template.h" 

extern template class Foo<int>;

int main() {
	//Foo<int> f;
	//std::cout << f.bar() << std::endl;
}

#include <iostream>
#include <vector>

class Foo {
	std::vector<int> vec1 = std::vector<int>(3, 0);
	std::vector<int> vec2 {0, 0, 0};
public:
	Foo() = default;
	Foo(int i) : vec1(3, i), vec2(3, i) {}

};

int main() {

}

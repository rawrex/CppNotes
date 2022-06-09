#include <iostream>
#include <string>

class A {
public:
	int x;
	double y;
	std::string s;
	void show() const {
		std::cout << x << ' ' << y << ' ' << s << std::endl;
	}
};
 
int main() {
	A a{2011, 3.14, "foo"};
	a.show();
}

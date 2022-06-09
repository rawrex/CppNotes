#include <iostream> 

class B {
public:
	virtual int foo() {
		std::cout << "B::foo()" << std::endl;
		return 333333;
	}
};

class D1: public B {
public:
	using B::foo;	
	int foo(int i) {
		std::cout << "D1::foo(int)" << std::endl;
		return i;
	}

};

int main() {
	B b;
	D1 d1;
	D1* d1p = &d1;
	std::cout << d1p->foo() << std::endl;
}

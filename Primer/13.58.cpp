#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
	friend std::ostream& operator<<(std::ostream &, const Foo&); 
	std::vector<int> data;
public:
	Foo(std::initializer_list<int> li = {}) : data(li) {}
	
	Foo sorted() && {
		std::cout << "&&" << '\n';
		std::sort(data.begin(), data.end());
		return *this;
	}
	Foo sorted() const& {
		std::cout << "const&" << '\n';
		return Foo(*this).sorted();
	}
};

std::ostream& operator<<(std::ostream &os, const Foo& f) {
	for (const int &i : f.data)
		os << i << " ";
	return os;
}
int main () {
	Foo f({2,3,1});	
	std::cout << f.sorted() << '\n';
	std::cout << Foo({5,4,6}).sorted() << std::endl;
}

#include <iostream>
#include <memory>
#include <string>

class DebugDelete {
	std::ostream& os;
public:
	DebugDelete(std::ostream& os = std::cout) : os(os) {}
	template <typename T> void operator()(T* p) {
		os << "Deleted: " << p << ' ' << *p << '\n';
		delete p;
	}
};

int main () {
	DebugDelete d;
	std::unique_ptr<std::string, DebugDelete> up(new std::string("Foo"), d);
}

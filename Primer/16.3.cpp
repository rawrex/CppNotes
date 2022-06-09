#include <iostream>
#include <sstream>
#include <string>


// Ex 16.48
class Foo {
	friend std::ostream& operator<<(std::ostream&, const Foo&);
	std::string data;
public:
	Foo(const std::string& s) : data(s) {}
};

std::ostream& operator<<(std::ostream& os, const Foo& f) {
	return os << f.data + "_BAR";
}

// // // // 

void print_name(const std::string& name) {
	std::cout << name << std::endl;
}

template <typename T> std::string debug_rep(const T& t) {
	print_name("<T> (const T&)");
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> std::string debug_rep(T* t) {
	print_name("<T> (T*)");
	std::ostringstream ret;
	ret << "Address: " << t << "; Value: ";
	if (t)
		ret << debug_rep(*t);
	else 
		ret << "nullptr";
	return ret.str();
}

std::string debug_rep(const std::string& s) {
	print_name("(const string&)");
	return '"' + s + '"';
}


// Ex 16.65
//std::string debug_rep(const char* pc) {
//	print_name("(const char*)");
//	return debug_rep(std::string(pc));
//}
//
//std::string debug_rep(char* pc) {
//	print_name("(char*)");
//	return debug_rep(std::string(pc));
//}

template<>
std::string debug_rep(char* pc) {
	print_name("<> (char*)");
	return debug_rep(std::string(pc));
}
template<>
std::string debug_rep(const char* pc) {
	print_name("<> (const char*)");
	return debug_rep(std::string(pc));
}




// Ex 16.49

template <typename T> void foo(T) {print_name("(T)");}
template <typename T> void foo(const T*) {print_name("(cosnt T*)");}


int main() {
	const char* p2 = "bar";
	debug_rep(p2);
}

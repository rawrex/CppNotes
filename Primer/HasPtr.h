#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>


struct HasPtrNoSwap {
friend void swap(HasPtrNoSwap&, HasPtrNoSwap&);
	HasPtrNoSwap(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	// Copy control
	HasPtrNoSwap(const HasPtrNoSwap &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {
		std::cout << "Copy constructor" << std::endl; 	
	}
	HasPtrNoSwap& operator=(const HasPtrNoSwap &rhs) {
		std::cout << "Copy-assignment" << std::endl;
		std::string *tmp = new std::string(*rhs.ps);
		delete ps;
		ps = tmp;
		i = rhs.i;
		return *this;
	}
	~HasPtrNoSwap() { delete ps; }
	HasPtrNoSwap(HasPtrNoSwap &&p) noexcept :
		ps(p.ps), i(p.i) { p.ps = 0; std::cout << "Move constructor" << std::endl; }
	const std::string val() { return *ps; }
private:
	std::string *ps;
	int i;
};
void swap(HasPtrNoSwap &a, HasPtrNoSwap &b) {
	using std::swap;
	std::cout << "START" << std::endl;
	std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
	swap(a.ps, b.ps);
	swap(a.i, b.i);
	std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
	std::cout << "END" << std::endl;
}




struct HasPtrSwap {
//friend void swap(HasPtrSwap&, HasPtrSwap&);
	HasPtrSwap(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	// Copy control
	HasPtrSwap(const HasPtrSwap &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {
		std::cout << "Copy constructor" << std::endl; 	
	}
	HasPtrSwap& operator=(HasPtrSwap rhs) {
		std::cout << "Copy-and-swap" << std::endl;
		swap(*this, rhs);
		return *this;
	}
	~HasPtrSwap() { delete ps; }
	HasPtrSwap(HasPtrSwap &&p) noexcept :
		ps(p.ps), i(p.i) { p.ps = 0; std::cout << "Move constructor" << std::endl; }
	const std::string val() { return *ps; }
private:
	std::string *ps;
	int i;
};


//inline void swap(HasPtrSwap &a, HasPtrSwap &b) {
//	using std::swap;
//	std::cout << "START" << std::endl;
//	std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
//	swap(a.ps, b.ps);
//	swap(a.i, b.i);
//	std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
//	std::cout << "END" << std::endl;
//}


#endif

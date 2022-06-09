#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <utility> 
#include <iterator>

struct MyString {
friend bool operator==(const MyString&, const MyString&);
friend bool operator!=(const MyString&, const MyString&);
friend std::ostream& operator<<(std::ostream&, const MyString&);
friend bool operator<(const MyString&, const MyString&);
	// Constructors
	MyString() : elements(nullptr), first_free(nullptr), capac(nullptr) {}
	MyString(std::initializer_list<char> li) {
		auto new_data = allocate_and_copy(li.begin(), li.end());
		elements = new_data.first;
		first_free = capac = new_data.second;
	}
	MyString(const char *cs) {
		const char *p = cs;
		while (*p != '\0') {
			++p;
		}
		auto pr = allocate_and_copy(cs, p);
		elements = pr.first;
		first_free = capac = pr.second;
	}

	// Operators
	const char& operator[](const size_t& i) const {
		return elements[i];
	}
	char& operator[](const size_t& i) {
		return elements[i];
	}
			
	
	// Copy-control
	~MyString();
	MyString(const MyString&); 
	MyString& operator=(const MyString &rhs);
	MyString(MyString &&) noexcept;
	MyString& operator=(MyString &&) noexcept;

	// Member functions
	size_t size() { return first_free - elements; }
	void push_back(const char &c) {
		check_and_allocate();
		alloc.construct(first_free++, c);
	}
	// Memo mgt
	void reserve(const size_t&);
	size_t capacity() { return capac - elements; }
	void resize(const size_t &, const char & = ' ');
	
	
	// Iterators
	char* my_begin() const { return elements; }
	char* my_end() const { return first_free; }
	const char* cbegin() const { return elements; }
	const char* cend() const { return first_free; }
private:
	// Data members
	static std::allocator<char> alloc;	
	char *elements, *first_free, *capac;
	
	// Utility functions
	std::pair<char*,char*> 
		allocate_and_copy(const char *b, const char *e);
	void free();
	void check_and_allocate() { if (size() == capacity()) reallocate(); }
	void reallocate(const size_t & = 0);

	
	void shrink(const size_t &);
};

// Static member definition
std::allocator<char> MyString::alloc;



// Utility funcitons

// Allocates new memo and copies the elements from the given range to that memo
std::pair<char*,char*> 
MyString::allocate_and_copy(const char *b, const char *e) {
	auto new_data = alloc.allocate(e-b);
	return {new_data, std::uninitialized_copy(b,e, new_data)} ;
}

void MyString::free() {
	if (elements) { // cannot pass null pointer to deallocate
		// inside lambda: in THIS call destroy on the address of the string passed by reference to the lambda
		std::for_each(elements, first_free, [this](char &rhs){ alloc.destroy(&rhs); }); 
		alloc.deallocate(elements, capacity());
	}
}
void MyString::reallocate(const size_t &explicit_size) {
	// Compute the size and allocate new memo
	size_t new_capacity;
	if (explicit_size)
		new_capacity = explicit_size;
	else
		new_capacity = size() ? size() * 2 : 1;
	auto new_memo = alloc.allocate(new_capacity);
	auto dest = new_memo; // Points to the first position in the new memo
	auto elem = elements; // Points to the first position in the old memo

	// Move the elements to the new memo from the old one
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free(); // Clean up the old memo

	// Bookkeeping of data members
	elements = new_memo;
	first_free = dest;
	capac = elements + new_capacity;
}


// Memo mgt members
void MyString::shrink(const size_t &new_size) {
	// first_free = capac 
	auto p = first_free;
	auto limit = elements + new_size;
	while (p != limit)
		// will destroy up to the limit and plus one elem,
		// so to have the "end pointer" to one past the last elem
		alloc.destroy(--p);
	// Deallocate memo starting from the next position from the limit
	alloc.deallocate(limit+1, capacity());
	// Bookkeeping of the pointers data members 
	first_free = capac = limit;
}

void MyString::reserve(const size_t &new_size) {
	// Should be called only with the new_size >= size()
	if (new_size > size())
		reallocate(new_size);
}

void MyString::resize(const size_t &new_size, const char &s) {
	if (size() > new_size)
		shrink(new_size);
	else {
		reallocate(new_size);	
		std::uninitialized_fill(first_free, capac, s);
		first_free = capac = elements + new_size;
	}
}


// Copy-control members

// Copy-constructor
MyString::MyString(const MyString &sv) {
	std::cout << "Copy constructor" << std::endl;
	auto new_data = allocate_and_copy(sv.cbegin(), sv.cend());
	elements = new_data.first;
	first_free = capac = new_data.second;
}

// Destructor
MyString::~MyString() { std::cout << "Destructor" << std::endl; free(); }

// Copy-assignment operator
MyString& MyString::operator=(const MyString &rhs) {
	std::cout << "Copy-assignment" << std::endl;
	auto new_data = allocate_and_copy(rhs.cbegin(), rhs.cend());
	free();
	elements = new_data.first;
	first_free = capac = new_data.second;
	return *this;	
}

MyString::MyString(MyString &&sv) noexcept
    : elements(sv.elements), first_free(sv.first_free), capac(sv.capac) {
		std::cout << "Move constructor" << std::endl;
		sv.elements = sv.first_free = sv.capac = nullptr;
	}

MyString& MyString::operator=(MyString &&rhs) noexcept {
	std::cout << "Move assignment" << std::endl;
    if (&rhs != this) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        capac = rhs.capac;
        rhs.elements = rhs.first_free = rhs.capac = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& ms) {
	for (auto i = ms.cbegin(); i != ms.cend(); ++i)
		os << *i;
	return os;
}
bool operator==(const MyString& a, const MyString& b) {
	auto ab(a.cbegin()), bb(b.cbegin());
	while (ab != a.cend() && bb != b.cend() && *ab == *bb) {
		++ab;
		++bb;
	}
	return ab == a.cend() && bb == b.cend();
}

bool operator!=(const MyString& a, const MyString& b) {
	return !(a == b);
}
bool operator<(const MyString& a, const MyString& b) {
	std::cout << "operator<" << std::endl;
	auto ab(a.cbegin()), bb(b.cbegin());
	for (/* empty */; ab != a.cend() && bb != b.cend() && *ab <= *bb; ++ab, ++bb) 
		std::cout << *ab << " vs " << *bb << '\n';
	return (ab == a.cend()) && (bb == b.cend());
}
#endif

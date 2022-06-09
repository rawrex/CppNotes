#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <utility> 

struct StrVec {
friend bool operator==(const StrVec&, const StrVec&);
friend bool operator!=(const StrVec&, const StrVec&);
friend bool operator<(const StrVec&, const StrVec&);
friend std::ostream& operator<<(std::ostream&, const StrVec&);

	// Constructors
	StrVec() : elements(nullptr), first_free(nullptr), capac(nullptr) {}
	StrVec(const std::initializer_list<std::string> &lt) { 
		auto p = allocate_and_copy(lt.begin(),lt.end());
		elements = p.first;
		first_free = capac = p.second;	
	}

	// Copy-control
	~StrVec();
	StrVec(const StrVec&); 
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(const StrVec &);
	StrVec& operator=(StrVec &&) noexcept;
	
	// Operators
	StrVec& operator=(const std::initializer_list<std::string>& lt) {
		*this=std::move(StrVec(lt));
		return *this;
	}
	const std::string& operator[](const size_t& i) const {
		return elements[i];
	}	
	std::string& operator[](const size_t& i) {
		return elements[i];
	}	

	// Member functions
	size_t size() { return first_free - elements; }
	void push_back(const std::string &s) {
		check_and_allocate();
		alloc.construct(first_free++, s);
	}
	// Memo mgt
	void reserve(const size_t&);
	size_t capacity() { return capac - elements; }
	void resize(const size_t &, const std::string & = std::string());
	
	
	// Iterators
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	const std::string* cbegin() const { return elements; }
	const std::string* cend() const { return first_free; }
private:
	// Data members
	static std::allocator<std::string> alloc;	
	std::string *elements, *first_free, *capac;
	
	// Utility functions
	std::pair<std::string*,std::string*> 
		allocate_and_copy(const std::string *b, const std::string *e);
	void free();
	void check_and_allocate() { if (size() == capacity()) reallocate(); }
	void reallocate(const size_t & = 0);
	void shrink(const size_t &);
};

// Static member definition
std::allocator<std::string> StrVec::alloc;



// Utility funcitons

// Allocates new memo and copies the elements from the given range to that memo
std::pair<std::string*,std::string*> 
StrVec::allocate_and_copy(const std::string *b, const std::string *e) {
	auto new_data = alloc.allocate(e-b);
	return {new_data, uninitialized_copy(b,e, new_data)} ;
}

// Destroys all the elements in THIS and deallocates the memory
// void StrVec::free() {
// 	if (elements) { // cannot pass null pointer to deallocate
// 		auto p = first_free;
// 		while (p != elements)
// 			alloc.destroy(--p);
// 		alloc.deallocate(elements, capacity());
// 	}
// }
// Ex 13.43
void StrVec::free() {
	if (elements) { // cannot pass null pointer to deallocate
		// inside lambda: in THIS call destroy on the address of the string passed by reference to the lambda
		std::for_each(elements, first_free, [this](std::string &rhs){ alloc.destroy(&rhs); }); 
		alloc.deallocate(elements, capacity());
	}
}
void StrVec::reallocate(const size_t &explicit_size) {
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
void StrVec::shrink(const size_t &new_size) {
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

void StrVec::reserve(const size_t &new_size) {
	// Should be called only with the new_size >= size()
	if (new_size > size())
		reallocate(new_size);
}

void StrVec::resize(const size_t &new_size, const std::string &s) {
	if (size() > new_size)
		shrink(new_size);
	else {
		reallocate(new_size);	
		uninitialized_fill(first_free, capac, s);
		first_free = capac = elements + new_size;
	}
}


// Copy-control members

// Copy-constructor
StrVec::StrVec(const StrVec &sv) {
	auto new_data = allocate_and_copy(sv.cbegin(), sv.cend());
	elements = new_data.first;
	first_free = capac = new_data.second;
}

// Destructor
StrVec::~StrVec() { free(); }

// Copy-assignment operator
StrVec& StrVec::operator=(const StrVec &rhs) {
	auto new_data = allocate_and_copy(rhs.cbegin(), rhs.cend());
	free();
	elements = new_data.first;
	first_free = capac = new_data.second;
	return *this;	
}

StrVec::StrVec(StrVec &&sv) noexcept 
	: elements(sv.elements), first_free(sv.first_free), capac(sv.capac) 
	{ sv.elements = sv.first_free = sv.capac = nullptr; }

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (&rhs != this) {
		free();		
		elements = rhs.elements;	
		first_free = rhs.first_free;
		capac = rhs.capac;
		rhs.elements = rhs.first_free = rhs.capac = nullptr;
	}
	return *this;
}

bool operator==(const StrVec& a, const StrVec& b) {
	auto ia = a.cbegin(), ib = b.cbegin();
	for (; ia != a.cend() && ib != b.cend() && *ia == *ib;
		++ia, ++ib);
	return (ia == a.cend()) && (ib == b.cend());
}
bool operator!=(const StrVec& a, const StrVec& b) {
	return !(a == b);
}
bool operator<(const StrVec& a, const StrVec& b) {
	auto ia = a.cbegin(), ib = b.cbegin();
	for (/* empty */; ia != a.cend() && ib != b.cend() && (*ia <= *ib); ++ia, ++ib);
	return (ia == a.cend()) && (ib == b.cend());
}
std::ostream& operator<<(std::ostream& os, const StrVec& sv) {
	for (auto i : sv)
		os << i << " ";
	return os;
}
#endif

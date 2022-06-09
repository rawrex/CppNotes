#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <utility> 


template <typename T> class Vec;

template <typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator<(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator<<(const Vec<T>&, const Vec<T>&);

template <typename T> class Vec {
	// Data members
	static std::allocator<T> alloc;	
	T *elements, *first_free, *capac;
	
	// Utility functions
	std::pair<T*,T*> 
		allocate_and_copy(const T *b, const T *e);
	void free();
	void check_and_allocate() { if (size() == capacity()) reallocate(); }
	void reallocate(const size_t & = 0);
	void shrink(const size_t &);

public:
	// Constructors
	Vec() : elements(nullptr), first_free(nullptr), capac(nullptr) {}
	Vec(const std::initializer_list<T> &lt)
		: elements(nullptr), first_free(nullptr), capac(nullptr) { 
		auto p = allocate_and_copy(lt.begin(),lt.end());
		elements = p.first;
		first_free = capac = p.second;	
	}

	// Copy-control
	~Vec();
	Vec(const Vec&); 
	Vec(Vec&&) noexcept;
	Vec& operator=(const Vec &);
	Vec& operator=(Vec &&) noexcept;
	
	// Operators
	Vec& operator=(const std::initializer_list<T>& lt) {
		*this=std::move(Vec(lt));
		return *this;
	}
	const T& operator[](const size_t& i) const {
		return elements[i];
	}	
	T& operator[](const size_t& i) {
		return elements[i];
	}	

	// Member functions
	size_t size() { return first_free - elements; }
	void push_back(const T &s) {
		check_and_allocate();
		alloc.construct(first_free++, s);
	}
	template <typename... Args>
	void emplace_back(Args&&... args) {
		check_and_allocate();
		alloc.construct(first_free++, std::forward<Args>(args)...);
	}
	// Memo mgt
	void reserve(const size_t&);
	size_t capacity() { return capac - elements; }
	void resize(const size_t &, const T & = T());
	
	
	// Iterators
	T* begin() const { return elements; }
	T* end() const { return first_free; }
	const T* cbegin() const { return elements; }
	const T* cend() const { return first_free; }
};

// Static member definition
template <typename T>
std::allocator<T> Vec<T>::alloc;



// Utility funcitons

// Allocates new memo and copies the elements from the given range to that memo
template <typename T> std::pair<T*,T*> 
Vec<T>::allocate_and_copy(const T *b, const T *e) {
	auto new_data = alloc.allocate(e-b);
	return {new_data, uninitialized_copy(b,e, new_data)} ;
}

// Destroys all the elements in THIS and deallocates the memory
// void Vec::free() {
// 	if (elements) { // cannot pass null pointer to deallocate
// 		auto p = first_free;
// 		while (p != elements)
// 			alloc.destroy(--p);
// 		alloc.deallocate(elements, capacity());
// 	}
// }

// Ex 13.43
template <typename T>
void Vec<T>::free() {
	if (elements) { // cannot pass null pointer to deallocate
	// inside lambda:
	// in THIS call destroy on the address of the string
	// passed by reference to the lambda
		std::for_each(elements, first_free, [this](T &rhs){ alloc.destroy(&rhs); }); 
		alloc.deallocate(elements, capacity());
	}
}
template <typename T>
void Vec<T>::reallocate(const size_t &explicit_size) {
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
template <typename T>
void Vec<T>::shrink(const size_t &new_size) {
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

template <typename T>
void Vec<T>::reserve(const size_t &new_size) {
	// Should be called only with the new_size >= size()
	if (new_size > size())
		reallocate(new_size);
}

template <typename T>
void Vec<T>::resize(const size_t &new_size, const T &s) {
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
template <typename T>
Vec<T>::Vec(const Vec &sv)
	: elements(nullptr), first_free(nullptr), capac(nullptr) {
	auto new_data = allocate_and_copy(sv.cbegin(), sv.cend());
	elements = new_data.first;
	first_free = capac = new_data.second;
}

// Destructor
template <typename T>
Vec<T>::~Vec() { free(); }

// Copy-assignment operator
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs) {
	auto new_data = allocate_and_copy(rhs.cbegin(), rhs.cend());
	free();
	elements = new_data.first;
	first_free = capac = new_data.second;
	return *this;	
}

template <typename T>
Vec<T>::Vec(Vec &&sv) noexcept
	: elements(sv.elements), first_free(sv.first_free), capac(sv.capac) {
		sv.elements = sv.first_free = sv.capac = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept {
	if (&rhs != this) {
		free();		
		elements = rhs.elements;	
		first_free = rhs.first_free;
		capac = rhs.capac;
		rhs.elements = rhs.first_free = rhs.capac = nullptr;
	}
	return *this;
}

template <typename T>
bool operator==(const Vec<T>& a, const Vec<T>& b) {
	auto ia = a.cbegin(), ib = b.cbegin();
	for (; ia != a.cend() && ib != b.cend() && *ia == *ib;
		++ia, ++ib);
	return (ia == a.cend()) && (ib == b.cend());
}
template <typename T>
bool operator!=(const Vec<T>& a, const Vec<T>& b) {
	return not(a == b);
}
template <typename T>
bool operator<(const Vec<T>& a, const Vec<T>& b) {
	auto ia = a.cbegin(), ib = b.cbegin();
	for (/* empty */; ia != a.cend() && ib != b.cend() && (*ia <= *ib); ++ia, ++ib);
	return (ia == a.cend()) && (ib == b.cend());
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& sv) {
	for (auto i : sv)
		os << i << " ";
	return os;
}
#endif

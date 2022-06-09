#ifndef BLOBPTR_H
#define BLODPTR_H

#include <iostream>
#include <memory>
#include <string>
#include "Blob.h"


template <typename T> class BlobPtr;
template <typename T> BlobPtr<T> operator-(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> BlobPtr<T> operator+(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> class Blob;

template <typename T> class BlobPtr {
	// Friends
	friend bool operator== <T>(const BlobPtr&, const BlobPtr&);
	// operator=! uses the operator==
	friend bool operator< <T>(const BlobPtr&, const BlobPtr&);
	friend BlobPtr operator- <T>(const BlobPtr&, const BlobPtr&);
	friend BlobPtr operator+ <T>(const BlobPtr&, const BlobPtr&);

	// Type shortcut
	typedef typename Blob<T>::size_type size_type;

	// Data members
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
	
	// Private utility function(s)
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;
	size_type size() const {
		auto ptr = wptr.lock();
		return ptr->size();
	}

public:

	// Copy control
	BlobPtr(const BlobPtr&) = default;
	BlobPtr& operator=(const BlobPtr&) = default;
	~BlobPtr() = default;
	
	// Operators
	const T& operator[](const size_t& i) const {
		auto p = check(i, "Dereference past the end");
		return (*p)[i];
	}
	T& operator[](const size_t& i) {
		auto p = check(i, "Dereference past the end");
		return (*p)[i];
	}
	T& operator*() const {
    	auto p = check(curr, "Dereference past the end");
    	return (*p)[curr];
	}
	BlobPtr& operator++() {
		check(curr, "Increment past the end");
		++curr;
		return *this;
	}
	T* operator->() const {
		return & this->operator*();
	}
	BlobPtr operator++(int) {
		BlobPtr tmp(*this);
		this->operator++();
		return tmp;
	}
	BlobPtr& operator--() {
		--curr;
		check(curr, "Increment past the end");
		return *this;
	}
	BlobPtr operator--(int) {
		BlobPtr tmp(*this);
		this->operator--();
		return tmp;
	}
	BlobPtr& operator-=(const BlobPtr& rhs) {
		curr -= rhs.curr;
		return *this;
	}
	BlobPtr& operator+=(const BlobPtr& rhs) {
		curr += rhs.curr;
		return *this;
	}
	
	BlobPtr() : wptr(/* Implicitly default */), curr(0) {}
	BlobPtr(Blob<T>& b, const size_t& i = 0) : wptr(b.data), curr(i) {}

};

template <typename T> std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string& msg) const {
	auto ptr = wptr.lock();
	if (!ptr) // Does the object exists?
		throw std::runtime_error("Unbound BlobPtr");
	if (i >= ptr->size()) // Is the index illegal?
		throw std::out_of_range(msg);
	return ptr;
}

template <typename T>
bool operator==(const BlobPtr<T>& a, const BlobPtr<T>& b) {
	return a.wptr.lock() == b.wptr.lock() && a.curr == b.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T>& a, const BlobPtr<T>& b) {
	return not(a == b);
}
template <typename T>
bool operator<(const BlobPtr<T>& a, const BlobPtr<T>& b) {
	return (a.curr < b.curr);
}
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	BlobPtr<T> tmp(lhs);
	return tmp+=rhs;
}
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	BlobPtr<T> tmp(lhs);
	return tmp-=rhs;
}

#endif

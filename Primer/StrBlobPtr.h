#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "StrBlob.h"

struct StrBlobPtr {
friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
friend StrBlobPtr operator-(const StrBlobPtr&, const StrBlobPtr&);
friend StrBlobPtr operator-(const StrBlobPtr&, const size_t&);
friend StrBlobPtr operator+(const StrBlobPtr&, const StrBlobPtr&);
friend StrBlobPtr operator+(const StrBlobPtr&, const size_t&);



    // copying from the StrBlob. Is it even ok to copy?
    typedef std::vector<std::string>::size_type size_type;
    
    // Constructors
    StrBlobPtr() : wptr(), curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)  {}
	StrBlobPtr(const StrBlobPtr &sbp) 
			: wptr(sbp.wptr), curr(sbp.curr) { std::cout << "Copy cons" << std::endl;}

	// Operators
	const std::string& operator[](const size_t& i) const {
		auto p = check(i, "Dereference past the end");
		return (*p)[i];
	}
	std::string& operator[](const size_t& i) {
		auto p = check(i, "Dereference past the end");
		return (*p)[i];
	}
	std::string& operator*() const {
    	auto p = check(curr, "Dereference past the end");
    	return (*p)[curr];
	}
	StrBlobPtr& operator++() {
		check(curr, "Increment past the end");
		++curr;
		return *this;
	}
	std::string* operator->() const {
		return & this->operator*();
	}
	StrBlobPtr operator++(int) {
		StrBlobPtr tmp(*this);
		this->operator++();
		return tmp;
	}
	StrBlobPtr& operator--() {
		--curr;
		check(curr, "Increment past the end");
		return *this;
	}
	StrBlobPtr operator--(int) {
		StrBlobPtr tmp(*this);
		this->operator--();
		return tmp;
	}
	StrBlobPtr& operator-=(const StrBlobPtr& rhs) {
		curr -= rhs.curr;
		return *this;
	}
	StrBlobPtr& operator+=(const StrBlobPtr& rhs) {
		curr += rhs.curr;
		return *this;
	}

    // Auxilary
    //size_type size() const {  auto p = wptr.lock(); return p->size(); }
private:
	// Utility function
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	
	// Data members
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
bool operator==(const StrBlobPtr& a, const StrBlobPtr& b) {
	return a.wptr.lock() == b.wptr.lock() &&
		a.curr == b.curr;
}
bool operator!=(const StrBlobPtr& a, const StrBlobPtr& b) {
	return !(a == b);
}
bool operator<(const StrBlobPtr& a, const StrBlobPtr& b) {
	return (a.curr < b.curr);
}

std::shared_ptr<std::vector<std::string>>
    StrBlobPtr::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) // is the object does not exist
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size()) // is index illegal
        throw std::out_of_range(msg);
    return ret;
}

StrBlobPtr operator+(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	StrBlobPtr tmp(lhs);
	return tmp+=rhs;
}
StrBlobPtr operator-(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	StrBlobPtr tmp(lhs);
	return tmp-=rhs;
}

// Pinter Arithmetic?!
StrBlobPtr operator-(const StrBlobPtr& lhs, const size_t& i) {
	StrBlobPtr tmp(lhs);
	for (size_t j=0; j < i; ++j)
		--tmp;
	return tmp;
}
StrBlobPtr operator+(const StrBlobPtr& lhs, const size_t& i) {
	StrBlobPtr tmp(lhs);
	for (size_t j=0; j < i; ++j)
		++tmp;
	return tmp;
}
//StrBlobPtr operator+=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
//	StrBlobPtr tmp(lhs);
//	return tmp+=rhs;
//}
#endif

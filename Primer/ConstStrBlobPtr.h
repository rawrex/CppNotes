#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "StrBlob.h"

struct ConstStrBlobPtr {
friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend ConstStrBlobPtr operator-(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend ConstStrBlobPtr operator-(const ConstStrBlobPtr&, const size_t&);
friend ConstStrBlobPtr operator+(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend ConstStrBlobPtr operator+(const ConstStrBlobPtr&, const size_t&);



    // copying from the StrBlob. Is it even ok to copy?
    typedef std::vector<std::string>::size_type size_type;
    
    // Constructors
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)  {}
	ConstStrBlobPtr(const ConstStrBlobPtr &sbp) : 
			wptr(sbp.wptr), curr(sbp.curr) { std::cout << "Copy cons" << std::endl;}

	// Operators
	const std::string& operator[](const size_t& i) const {
		auto p = check(i, "Dereference past the end");
		return (*p)[i];
	}
	const std::string& operator*() const {
    	auto p = check(curr, "Dereference past the end");
    	return (*p)[curr];
	}
	ConstStrBlobPtr& operator++() {
		check(curr, "Increment past the end");
		++curr;
		return *this;
	}
	const std::string* operator->() const {
		return & this->operator*();
	}
	ConstStrBlobPtr operator++(int) {
		ConstStrBlobPtr tmp(*this);
		this->operator++();
		return tmp;
	}
	ConstStrBlobPtr& operator--() {
		--curr;
		check(curr, "Increment past the end");
		return *this;
	}
	ConstStrBlobPtr operator--(int) {
		ConstStrBlobPtr tmp(*this);
		this->operator--();
		return tmp;
	}
	ConstStrBlobPtr& operator-=(const ConstStrBlobPtr& rhs) {
		curr -= rhs.curr;
		return *this;
	}
	ConstStrBlobPtr& operator+=(const ConstStrBlobPtr& rhs) {
		curr += rhs.curr;
		return *this;
	}

    // Auxilary
    size_type size() const {  auto p = wptr.lock(); return p->size(); }
private:
	// Utility function
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	
	// Data members
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
bool operator==(const ConstStrBlobPtr& a, const ConstStrBlobPtr& b) {
	return a.wptr.lock() == b.wptr.lock() &&
		a.curr == b.curr;
}
bool operator!=(const ConstStrBlobPtr& a, const ConstStrBlobPtr& b) {
	return !(a == b);
}
bool operator<(const ConstStrBlobPtr& a, const ConstStrBlobPtr& b) {
	return (a.curr < b.curr);
}

std::shared_ptr<std::vector<std::string>>
    ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) // is the object does not exist
        throw std::runtime_error("Unbound ConstStrBlobPtr");
    if (i >= ret->size()) // is index illegal
        throw std::out_of_range(msg);
    return ret;
}

ConstStrBlobPtr operator+(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
	ConstStrBlobPtr tmp(lhs);
	return tmp+=rhs;
}
ConstStrBlobPtr operator-(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
	ConstStrBlobPtr tmp(lhs);
	return tmp-=rhs;
}

// Pinter Arithmetic?!
ConstStrBlobPtr operator-(const ConstStrBlobPtr& lhs, const size_t& i) {
	ConstStrBlobPtr tmp(lhs);
	for (size_t j=0; j < i; ++j)
		--tmp;
	return tmp;
}
ConstStrBlobPtr operator+(const ConstStrBlobPtr& lhs, const size_t& i) {
	ConstStrBlobPtr tmp(lhs);
	for (size_t j=0; j < i; ++j)
		++tmp;
	return tmp;
}
//ConstStrBlobPtr operator+=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
//	ConstStrBlobPtr tmp(lhs);
//	return tmp+=rhs;
//}
#endif

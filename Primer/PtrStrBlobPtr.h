#ifndef PTRSTRBLOBPTR_H
#define PTRSTRBLOBPTR_H

#include "StrBlobPtr.h"

class PtrStrBlobPtr {
	StrBlobPtr* pointer;
	std::size_t curr;


public:
	PtrStrBlobPtr (StrBlobPtr* p, size_t c = 0) : pointer(p), curr(c) {}

	StrBlobPtr& operator*() const {
		return *pointer;
	}
	StrBlobPtr* operator->() const {
		return & this->operator*();
	}
};
#endif

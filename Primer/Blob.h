#ifndef BLOB_H
#define BLOB_H

#include <iostream>
#include <vector>
#include "Memory.h"

template <typename T> class BlobPtr;
template <typename T> class Blob;

template <typename T> std::ostream& operator<<(std::ostream& os, const Blob<T>& sb);
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
friend class BlobPtr<T>;
friend bool operator== <T>(const Blob&, const Blob&);
friend bool operator< <T>(const Blob&, const Blob&);
// uses operator==, which is already a friend
//friend bool operator!=<T>(const Blob&, const Blob&);
friend std::ostream& operator<< <T>(std::ostream& os, const Blob& sb);

	// Type shortcut
	typedef typename std::vector<T>::size_type size_type;
	
	// Data member
    SharedPtr<std::vector<T>> data;
	
	// Utility funciton
    void check(size_type i, const std::string &msg) const;

public:
	Blob() : data(new std::vector<T> ()) {}
	template <typename Iter> Blob(Iter b, Iter e) 
		: data(new std::vector<T>(b, e)) {}
	Blob(std::initializer_list<T> lt)
		: data(new std::vector<T> (lt)) {}
	
	typename std::vector<T>::iterator begin() {
		return data->begin();
	}
	typename std::vector<T>::iterator end() {
		return data->end();
	}

    // Add and remove
    void push_back(const T&); // should it be a reference or const?
	void push_back(T&&);
    void pop_back();

    // Access
    T& front();
    T& back();
    T& front() const;
    T& back() const;
	
	// Operators
	const T& operator[](const size_t& i) const {
		return (*data)[i];
	}	
	T& operator[](const size_t& i) {
		return (*data)[i];
	}	

	// Copy control
	Blob(const Blob& rhs)
		: data(new std::vector<T>(*rhs.data)) {}
	Blob(Blob&& rhs)
		: data(new std::vector<T>(std::move(*rhs.data))) {}

	Blob& operator=(const Blob& rhs) { 
		data = new std::vector<T> (*rhs.data);
		return *this;
	}
	Blob& operator=(Blob&& rhs) { 
		data = new std::vector<T> (std::move(*rhs.data));
		return *this;
	}
	~Blob() = default;

	// Public utility functions 
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
	
};

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::front() {
    check(0, "front() on empty Blob");
    return data->front();
}
template <typename T> T& Blob<T>::back() {
    check(0, "back() on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::front() const {
    check(0, "front() on empty Blob");
    return data->front();
}
template <typename T> T& Blob<T>::back() const {
    check(0, "back() on empty Blob");
    return data->back();
}

template <typename T> void Blob<T>::push_back(const T& item) {
    data->push_back(item);
}
template <typename T> void Blob<T>::push_back(T&& item) {
	data->push_back(std::move(item));
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "Pop back on empty Blob");
    data->pop_back();
}

template <typename T> bool operator==(const Blob<T>& a, const Blob<T>& b){
	return *(a.data) == *(b.data);
}
template <typename T> bool operator!=(const Blob<T>& a, const Blob<T>& b){
	return not(a == b);
}
//bool operator<(const Blob &a, const Blob &b) {
//	return (*(a.data) < *(b.data));
//}


template <typename T> std::ostream& operator<<(std::ostream& os, const Blob<T>& sb) {
	for (auto i : *(sb.data))
		os << i << " ";
	return os;
}

#endif

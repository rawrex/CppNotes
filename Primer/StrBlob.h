#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <istream>
#include <vector>
#include <map>
#include <memory>
#include <new>
#include <fstream>
#include <sstream>
#include <iostream>

struct StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
friend std::ostream& operator<<(std::ostream&, const StrBlob&);
friend bool operator==(const StrBlob&, const StrBlob& );
friend bool operator!=(const StrBlob&, const StrBlob& );
friend bool operator<(const StrBlob&, const StrBlob& );

    typedef std::vector<std::string>::size_type size_type;
	
    // constructors
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

	//  begin Ex 13.26
	StrBlob(const StrBlob &rhs) : data(std::make_shared<std::vector<std::string>>(*rhs.data)) {}
	StrBlob& operator=(const StrBlob &rhs) { 
		data = std::make_shared<std::vector<std::string>> (*rhs.data);
		return *this;
	}
	// end EX 13.25

	const std::string& operator[](const size_t& i) const {
		return (*data)[i];
	}	
	std::string& operator[](const size_t& i) {
		return (*data)[i];
	}	
    // auxilary
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // Add and remove
    void push_back(const std::string &); // should it be a reference or const?
	void push_back(std::string &&);
    void pop_back();

    // Access
    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const; // throw msg is data[i] isn't valid
};

// Constructors definitions
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>> ()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>> (il)) {}

// Member funcitons definitions
void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front() {
    check(0, "front() on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back() {
    check(0, "back() on empty StrBlob");
    return data->back();
}

std::string& StrBlob::front() const {
    check(0, "front() on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back() const {
    check(0, "back() on empty StrBlob");
    return data->back();
}

void StrBlob::push_back(const std::string &s) {
    data->push_back(s);
}
void StrBlob::push_back(std::string &&s) {
	std::cout << "Move constructor" << std::endl;
	data->push_back(std::move(s));
}

void StrBlob::pop_back() {
    check(0, "Pop back on empty StrBlob");
    data->pop_back();
}

bool operator==(const StrBlob &a, const StrBlob &b) {
	return *(a.data) == *(b.data);
}
bool operator!=(const StrBlob &a, const StrBlob &b) {
	return !(a.data == b.data);
}
bool operator<(const StrBlob &a, const StrBlob &b) {
	return (*(a.data) < *(b.data));
}
std::ostream& operator<<(std::ostream& os, const StrBlob& sb) {
	for (auto i : *(sb.data))
		os << i << " ";
	return os;
}
#endif

//
//  Person_main.cpp
//  C++ Primer
//
//  Created by Supertoy on 14/02/2020.
//  Copyright © 2020 Org.Name. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <new>
#include <typeinfo>
#include <array>
#include <memory>
#include <cstdlib>
#include <numeric>
#include <iterator>
#include <random>
#include <functional>
#include <bitset>
#include <cstring>

//#define NDEBUG

using std::cin;
using std::cout; using std::endl; using std::cerr;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::runtime_error;
using std::initializer_list;



// Ex 7.9

struct Person {
friend std::istream &read(std::istream &is, Person &item);
friend std::ostream &print(std::ostream &os, Person &item);
    // Constructors
    Person() = default;
    Person(const std::string &n) : name(n) {}
    Person(const std::string &n, const std::string &add) : name(n), address(add) {}
    explicit Person(std::istream &is);
    //operations
    std::string get_name() const { return name; }
    std::string get_addr() const { return address; }
    
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &item) {
    is >> item.name; // >> item.address;
    return is;
}
std::ostream &print(std::ostream &os, Person &item) {
    os << item.name << " " << item.address;
    return os;
}

Person::Person(std::istream &is) {
    read(cin, *this);
}

//int main () {
//    Person one;
//    cout << "Enter it's name: ";
//    read(cin, one);
//    print(cout, one) << endl;
//    return 0;
//}


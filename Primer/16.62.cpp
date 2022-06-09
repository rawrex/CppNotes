//  Sales_data.h
//  C++ Primer
//
//  Created by Supertoy on 10/10/2019.

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include <unordered_set>

//template <typename T> struct std::hash;


class Sales_data {
//friend class std::hash<Sales_data>;
template <typename T> friend class std::hash;
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend Sales_data operator*(const Sales_data&, const Sales_data&);
friend std::ostream& operator<<(std::ostream &os, const Sales_data &);
friend std::istream& operator>>(std::istream &is, Sales_data &item);
friend bool operator==(const Sales_data&, const Sales_data&);
    
public:
    // Constructors
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) : Sales_data() { is >> *this; }
    
	Sales_data& operator*=(const int& i);	
    Sales_data& operator+=(const Sales_data &);
	Sales_data& operator=(const std::string& s) {
		bookNo = s;
		return *this;
	}	
	explicit operator std::string() { return bookNo; }
	explicit operator double() { return revenue; }
	explicit operator bool() { return units_sold > 0; }
	
    std::string isbn() const { return bookNo; }
    
private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream &os, const Sales_data &);
std::istream &read(std::istream &is, Sales_data &item);


//Aux funcitons defintions:
Sales_data operator*(const Sales_data& sd, const int& i) {
	Sales_data tmp(sd);
	tmp*=i;
	return tmp;
}
Sales_data& Sales_data::operator*=(const int& i) {
	units_sold *= i;
	revenue *= i;
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum+=rhs;
    return sum;
}

// Ex 14.21
//Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
//	auto bNo = lhs.bookNo;
//	auto units_sold = lhs.units_sold + rhs.units_sold;
//	auto revenue = lhs.revenue + rhs.revenue;
//	return Sales_data(bNo, units_sold, revenue/units_sold); // What?!
//}
//
//Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
//	Sales_data tmp = *this + rhs;
//	*this = tmp;
//	return *this;
//}

inline double Sales_data::avg_price() const
    { return units_sold ? revenue / units_sold : 0; }

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
	if (is) {
    	item.revenue = price * item.units_sold;
		std::cout << price << std::endl;
	}
	else
		item = Sales_data();
    return is;
}
std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << "#: " <<item.isbn() << "; sold: " << item.units_sold
    << "; revenue: " << item.revenue << "; avg_price: " << item.avg_price() << ".";
    return os;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNo == rhs.bookNo &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

namespace std {
	template<> struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& sd) const {
			return hash<string>()(sd.bookNo) ^
				hash<unsigned>()(sd.units_sold) ^
				hash<double>()(sd.revenue);
		}
	};
}
#endif 

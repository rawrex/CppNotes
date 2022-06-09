#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"
#include <set>
#include <iostream>
#include <memory>

class Basket {

	// Comparator for the basket
	static bool compare(const std::shared_ptr<Quote>& a, const std::shared_ptr<Quote>& b) {
		return a->isbn() < b->isbn();
	}
	// Basket contents
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

public:
	void add_item(const Quote& item) {
		items.insert(std::shared_ptr<Quote> (item.clone()));
	}
	void add_item(Quote&& item) {
		items.insert(std::shared_ptr<Quote> (std::move(item).clone()));
	}
	// Print and return sum for all items
	double total_reciept(std::ostream& = std::cout) const;
};


double Basket::total_reciept(std::ostream& os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(**iter, items.count(*iter), os);
	}
	os << sum;
	return sum;
}

#endif

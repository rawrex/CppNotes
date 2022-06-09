#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

int main(){
	std::unordered_set<Sales_data> set {
		Sales_data("XXX", 2, 2),
		Sales_data("XXO", 1, 2),
		Sales_data("XXT", 1, 2),
		Sales_data("XXX", 2, 2), // Duplicate
	};
	for (auto i : set)
		std::cout << i << std::endl;
}

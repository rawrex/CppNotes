#include <iostream>
#include "Bookstore/Sales_data.h"

namespace std {
	template<> struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& sd) const {
			return hash<string>()(sd.bookNo) ^
				hash<unsigned>()(sd.units_sold) ^
				hash<double>()(sd.revenue);
				
		}

	}
}

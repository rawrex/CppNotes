#include <iostream>
#include "Quote.h"
#include "Basket.h"
#include <memory>

int main(){
	
	Bulk b1("foo", 20.0, 4, .25);
	Bulk b2("bar", 20.0, 2, .5);
	Limit lim1("baz", 20.0, 2, .25);
	Quote q1("qux", 20.0);

	Basket basket;
	
	basket.add_item(b1);
	basket.add_item(b2);
	basket.add_item(lim1);
	basket.add_item(q1);
	
	basket.total_reciept();

}

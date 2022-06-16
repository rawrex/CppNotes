#include <iostream>
#include <string>

class YoungGroup
{
	static unsigned group_max_age;

	// Note that init_group_max_age is private
	static unsigned init_group_max_age()
	{
		const unsigned init_age = 25;	
		return init_age;
	}

	unsigned population;
	std::string name;

public:
	YoungGroup( unsigned p = 0, const std::string& n = "No Name") : population(p), name(n) {}

	static unsigned max_age()
	{
		return group_max_age;
	}

	static unsigned max_age(const unsigned & new_age) 
	{
		group_max_age = new_age;
		return group_max_age;
	}
};

// As with any other member definition,
// a static data member definition may access the private members of its class
// in this case, the init_group_max_age()
unsigned YoungGroup::group_max_age = init_group_max_age();

int main() {
	YoungGroup::max_age(33);
	std::cout << YoungGroup::max_age() << std::endl;
}

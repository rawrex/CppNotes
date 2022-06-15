#include <iostream>
#include <string>

class YoungGroup
{
	static unsigned group_max_age;
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

unsigned YoungGroup::group_max_age = init_group_max_age();

int main() {
	std::cout << YoungGroup::max_age() << std::endl;
}

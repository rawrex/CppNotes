#include <iostream>

class DeletedDtor
{
public:
	virtual ~DeletedDtor() = delete;
};

int main() {
	auto p = new DeletedDtor();
	// delete p;
}

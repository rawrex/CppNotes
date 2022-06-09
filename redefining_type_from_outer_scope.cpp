#include <iostream>
#include <string>

using bar = int*;

struct Foo 
{
	bar b = nullptr;
private:
	// error: declaration of ‘using bar = int*’ changes meaning of ‘bar’
	using bar = int*;
};


int main() {
	
}

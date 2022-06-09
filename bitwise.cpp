#include <iostream>

void print(unsigned long & number)
{
	auto n_bits = 32;
	for (auto i = n_bits; i; --i)
	{
		if(!(i%8))
			std::cout << ' ';
		if(number & (1UL << i))
			std::cout << '1';
		else
			std::cout << '0';
	}
	std::cout << std::endl;
}
void set(unsigned long& bits, unsigned long& i)
{
	// Compound-assignment bitwise-OR 
	// With unsigned long integer literal with value one
	// shifted i positions to the left.
	bits |= (1UL << i);

	// Result is that we set the i-th bit to one
}
void clear(unsigned long& bits, unsigned long& i)
{
	// Compound-assignment bitwise-AND 
	// With bitwise-NOTed unsigned long integer literal with value one
	// shifted i positions to the left.
	bits &= ~(1UL << i);

	// Result is that we set the i-th bit to zero
}

// Right shift (>>) operator is equivalent to division by 2
unsigned divByPowTwo(const int & i, unsigned p = 1)
{
	return i >> p;
}
// Left shift (<<) operator is equivalent to multiplication by 2
unsigned mulByPowTwo(const int & i, unsigned p = 1)
{
	return i << p;
}

// Use bitwise AND (&) operator to check even or odd number
bool isEven(const int & num)
{
	return !(num & 1UL);
}

// Quickly convert character to lowercase and uppercase
void toup(char & c)
{
	c |= ' ';
}	
void tolo(char & c)
{
	c &= '_';
}	

// Quick conditional assignment hack
// if (x == a)
//     x = b;
// if (x == b)
//     x = a;
//
// if (x == a) x = b;
// x = a ^ b ^ x;


// Swap two number without third variable
// Swap a with b
// a ^= b;
// b ^= a;
// a ^= b;

int main() {

	unsigned long bits = 0, i = 3;
	
	set(bits, i);
	print(bits);
	clear(bits, i);
	print(bits);

	int n = 32;
	std::cout << divByPowTwo(n, 2) << std::endl;
	
	std::cout << std::boolalpha << isEven(12) << ' ' << isEven(13) << std::endl;

	char t = 't';
	toup(t);
	std::cout << t << ' ';
	tolo(t);	
	std::cout << t << std::endl;

	// Swap numbers
	int a = 11, b = 22;
	std::cout << a << ' ' << b << std::endl;
	a^=b;
	b^=a;
	a^=b;
	std::cout << a << ' ' << b << std::endl;
}

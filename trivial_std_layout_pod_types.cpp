#include <iostream>
#include <cstring>

// The term layout refers to how the members of an object of class, struct or union type are arranged in memory.
// In some cases, the layout is well-defined by the language specification.
// But when a class or struct contains certain C++ language features 
// Such as:
//	- virtual base classes
//	- virtual functions
//	- members with different access control

// Then the compiler is free to choose a layout.
// That layout may vary depending on what optimizations are being performed 
// and in many cases the object might not even occupy a contiguous area of memory.

// E.g. if a class has virtual functions,
// all the instances of that class might share a single virtual function table.
// Such types are very useful, but they also have limitations.
// Because the layout is undefined they cannot be passed to programs written in other languages, such as C,
// And because they might be non-contiguous they cannot be reliably copied with fast low-level functions such as memcopy,
// or serialized over a network.

// To enable compilers as well as C++ programs and metaprograms to reason about the suitability of any given type 
// for operations that depend on a particular memory layout,
// C++14 introduced three categories of simple classes and structs:
// 	- trivial:					is_trivial<T>
//	- standard-layout:			is_standard_layout<T> 
//	- POD (Plain Old Data):		is_pod<T> 

// Trivial types
//
// A class with implicitly defined or explicitly defaulted special member functions is a trivial type.
// It occupies a contiguous memory area. It can have members with different access specifiers.
// The compiler is free to choose how to order members in this situation.
// Therefore, you can memcopy such objects but you cannot reliably consume them from a C program.
// A trivial type T can be copied into an array of char or unsigned char, and safely copied back into a T variable.
// Note that because of alignment requirements, there might be padding bytes between type members.

// Trivial types have a trivial default constructor, trivial copy constructor,
// trivial copy assignment operator and trivial destructor.
// In each case, trivial means the operation is not user-provided and belongs to a class that
//	- has no virtual functions or virtual base classes,
//	- has no base classes with a corresponding non-trivial constructor/operator/destructor
//	- has no data members of class type with a corresponding non-trivial constructor/operator/destructor

// E.g.
struct Trivial
{
	Trivial() = default;
	Trivial(int x, int y) : a(x), b(y) {}
	int a;
private:
	int b;
};

int main() 
{
	Trivial f1 {21, 3};
	Trivial f2;
	unsigned char arr[10];

	std::memcpy(&arr, &f1, sizeof(Trivial));
	std::memcpy(&f2, arr, sizeof(Trivial));

	std::cout << f2.a << std::endl;
}

// Standard layout types
//
// A class that does not contain virtual functions and all members have the same access control.
// It is memcopy-able and the layout is sufficiently defined that it can be consumed by C programs.
// Standard-layout types can have user-defined special member functions.
// In addition, standard layout types have these characteristics:
//	- no virtual functions or virtual base classes
//	- all non-static data members have the same access control
//	- all non-static members of class type are standard-layout
//	- any base classes are standard-layout
//	- has no base classes of the same type as the first non-static data member.
//	- meets one of these conditions:
//		- no non-static data member in the most-derived class and no more than one base class with non-static data members
//		- or has no base classes with non-static data members

struct StdLayout
{
	// Same access
	int i;
	int j;

	// User-defined constructor OK
	StdLayout(int a, int b) : i(a), j(b) {} 
};

// The last two requirements demo:
struct Base
{
   int i;
   int j;
};

// std::is_standard_layout<Derived> == false...
struct Derived : public Base
{
	//...due to non-static data members
	int x;
	int y;
};


// POD types
//
// When a class or struct is both trivial and standard-layout, it is a POD (Plain Old Data) type.
// So, POD = StandardLayout + Trivial.
// The memory layout of POD types is therefore contiguous and each member has a higher address than the member that was declared before it,
// so that byte for byte copies and binary I/O can be performed on these types.
// Scalar types such as int are also POD types.
// POD types that are classes can have only POD types as non-static data members.

struct POD
{
   int a;
   int b;
};


// Literal types
// A literal type is one whose layout can be determined at compile time.
// The following are the literal types:
//	- Void
//	- Scalar types
//	- References
//	- Arrays of void, scalar types or references
//	- A class that has a trivial destructor, and one or more constexpr constructors that are not move or copy constructors.
//	  Additionally, all its non-static data members and base classes must be literal types and not volatile.

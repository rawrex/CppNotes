#include <iostream>
#include <string>

// Friendship is not transitive.
// Friendship is not inherited.

// Storage class specifiers are not allowed in friend function declarations.
// A function that is defined in the friend declaration has external linkage,
// a function that was previously defined, keeps the linkage it was defined with. 

// Access specifiers have no effect on the meaning of friend declarations.

// A friend class declaration cannot define a new class.

// When a local class declares an unqualified function or class as a friend,
// only functions and classes in the innermost non-class scope are looked up,
// not the global functions.

class Foo {
	friend void printFoo(const Foo& f)
	{
		std::cout << f.x << std::endl;
	}
	std::string x = "Default Value";
public:
	void memfn() const { printFoo(*this); }
	Foo() = default;
	Foo(const std::string& str) : x(str) {}
};


// Redeclare, ok
void printFoo(const Foo& f);
// error: redefinition of ‘void printFoo(const Foo&)’
// void printFoo(const Foo& f) {}


// Both function template and class template declarations 
// may appear with the friend specifier in any non-local class or class template 
// (although only function templates may be defined within the class
// or class template that is granting friendship).

void bar() 
{
	class Bar {
		// error: invalid declaration of member template in local class
		// template <typename T> friend void qux() {}
	};
}

// In this case, every specialization of the template becomes a friend,
// whether it is implicitly instantiated, partially specialized, or explicitly specialized. 

class A
{
    template<typename T>
    friend class B;			// every B<T> is a friend of A
 
    template<typename T>
    friend void f(T) {}		// every f<T> is a friend of A
};


// Friend declarations cannot refer to partial specializations,
// but can refer to full specializations:

template<class T>
class B {};					// Primary

template<class T>
class B<T*> {};				// Partial

// When a friend declaration refers to a full specialization of a function template
// The keyword inline and default arguments cannot be used in friend declaration
template<>
class B<int> {};			// Full

class X
{
    template<class T>
	// error: partial specialization ‘B<T*>’ declared ‘friend’
    // friend class B<T*>;	// Error
    friend class B<int>;	// Ok
};

int main()
{

	Foo f;
	printFoo(f);
	
}

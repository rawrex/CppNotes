class Foo {

	// error: ISO C++ forbids in-class initialization of non-const static member ‘Foo::data_b’
	static int data_a = 63;

	// OK, we may provide in-class initializer for data members that have const integral type
	const static int data_b = 42;

	// We must provide an in-class initializer for a static constexpr member 
	constexpr static int data_c = 21;

};

int main() {

}

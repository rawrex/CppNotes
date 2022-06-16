class Literal {
	double data_1;
	double data_2;
public:
	constexpr Literal(double d1, double d2) : data_1(d1), data_2(d2) {}
};

constexpr Literal global_data = {1.4141, 1.7320};

class Foo {

	// error: ISO C++ forbids in-class initialization of non-const static member 
	// Must be const
	static int data_a = 63;

	// OK, we may provide in-class initializer for data members that have const integral type
	const static int data_b = 42;

	// error: ‘constexpr’ needed for in-class initialization of static data member 
	// Not an integral type and not a constexpr
	const static Literal data_d = {1.4141, 1.7320};

	// We must provide an in-class initializer for a static constexpr member 
	constexpr static int data_c = 21;

	// OK, the member is a static constexpr and the initializer is a constexpr
	// Such a member is itself a constant expression 
	// and can be used where a constant expression is required
	constexpr static Literal data_d = global_data;

};

int main() {

}

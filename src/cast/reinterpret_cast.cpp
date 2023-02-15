#include <iostream>

void print(int* pi) 
{
	std::cout << pi << ' ' << *pi << std::endl;
}
void print(char* pc) 
{
	std::cout << pc << ' ' << *pc << std::endl;
}
void print(void* pv) 
{
	std::cout << pv << ' ' << "None" << std::endl;
}

// BASIC USAGE CASE
// 
void basic_use()
{
	int i = 21;

	// reinterpret_cast only guarantees that if you cast a pointer to a different type,
	// and then reinterpret_cast it back to the original type, you get the original value
	
	int* a = &i; 							print(a);
	char* b = reinterpret_cast<char*>(a);	print(b);
	void* c = reinterpret_cast<void*>(a);	print(c);
	int* d = reinterpret_cast<int*>(b);		print(d);
	
	// a and c contain the same value, but the value of b is unspecified. 
	// (in practice it will typically contain the same address as a and c, 
	// but that's not specified in the standard, 
	// and it may not be true on machines with more complex memory systems.)


}


// REAL WORLD DEMO CASE
//	
// One case when reinterpret_cast is necessary is when interfacing with opaque data types.
// This occurs frequently in vendor APIs over which the programmer has no control.
// Here's a contrived example where a vendor provides an API
// for storing and retrieving arbitrary global data:

// Vendor.hpp
struct Opaque { int x = 21;	};
using VendorData = Opaque*;
void setVendorData(VendorData p) {}
Opaque o {33};		// A hack for
VendorData vd = &o; // demo purpose
VendorData getVendorData() { return vd; }

// main.cpp
struct MyData {
	int y = 42;
};

void real_world()
{
	MyData my_data;

	// Set data
	VendorData vendor_data_1;
	// vendor_data_1 = &my_data;								// compile-time error
	// vendor_data_1 = static_cast<VendorData>(&my_data);		// compile error
	vendor_data_1 = reinterpret_cast<VendorData>(&my_data);		// ok
    setVendorData(vendor_data_1);

	// ...

	// Retrieve data
    VendorData vendor_data_2 = getVendorData(); 
	MyData * my_data_ptr = nullptr;
	// my_data_ptr = vendor_data_2;								// compile-time error
	// my_data_ptr = static_cast<MyData *>(vendor_data_2);		// compile-time error
	my_data_ptr = reinterpret_cast<MyData *>(vendor_data_2);	// ok

    if (my_data_ptr) std::cout << my_data_ptr->y << std::endl;
}

int main() {
	basic_use();
	real_world();
}

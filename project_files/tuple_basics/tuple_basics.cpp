#include <tuple>
#include <utility>
#include <iostream>
#include <typeinfo>

void basicTupleUses()
{
	std::tuple<const char*, std::string, std::wstring> strings_a { "foo", "bar", L"baz" };
	const auto strings_b = std::make_tuple("foo", "bar", L"baz");

	constexpr size_t size = std::tuple_size<decltype(strings_b)>::value;
	std::cout << "strings_b size: " << size << std::endl;

	std::cout << std::get<0>(strings_b) << std::endl;
	std::cout << std::get<1>(strings_b) << std::endl;
	std::wcout << std::get<2>(strings_b) << std::endl;

	std::cout << typeid(std::tuple_element<0, decltype(strings_a)>::type).name() << std::endl;
	std::cout << typeid(std::tuple_element<1, decltype(strings_a)>::type).name() << std::endl;
	std::cout << typeid(std::tuple_element<2, decltype(strings_a)>::type).name() << std::endl;


	std::tuple_element<0, decltype(strings_b)>::type first_element {};
	std::tuple_element<1, decltype(strings_b)>::type second_element {};
	std::tuple_element<2, decltype(strings_b)>::type third_element {};

	std::cout << typeid(std::tuple_element<0, decltype(strings_b)>::type).name() << std::endl;
	std::cout << typeid(std::tuple_element<1, decltype(strings_b)>::type).name() << std::endl;
	std::cout << typeid(std::tuple_element<2, decltype(strings_b)>::type).name() << std::endl;
}

void tupleCat()
{
	char ch = 'x';
	double pi = 3.1415;

	auto t1 = std::make_tuple<std::string, int>("foo", 1);
	auto t2 = std::make_tuple<size_t, double, std::pair<int, int>>(0, 3.14, { 11, 22 });

	// t3 will be a tuple with elements as lvalue references to the two local variables ch and pi
	auto t3 = std::tie(ch, pi);

	auto t = std::tuple_cat(t1, t2, t3);
}

int main()
{
	basicTupleUses();
	tupleCat();
}

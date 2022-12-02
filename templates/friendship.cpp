// Forward declare a template class that we're going to befriend with the Bar
template <typename T>
class Foo;

// Needed to declare the equality operator
template <typename T>
class Bar;

template <typename T>
bool operator==(const Bar<T>&, const Bar<T>&);

template <typename T>
class Bar
{
	friend class Foo<T>;
	friend bool operator==<T>(const Bar<T>&, const Bar<T>&);
};

int main() {

}

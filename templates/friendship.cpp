// Forward declare a template class that we're going to befriend with the Bar
template <typename Type>
class Friend;

// Needed to declare the equality operator
template <typename Type>
class MyClass;

template <typename Type>
bool operator==(const MyClass<T>&, const MyClass<T>&);

template <typename Type>
class MyClass
{
	// One-to-one friendship example (both the operator and the Foo)
	friend class Friend<Type>;
	friend bool operator==<Type>(const MyClass<Type>&, const MyClass<Type>&);
};

int main() {

}

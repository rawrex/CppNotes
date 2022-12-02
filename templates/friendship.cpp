// A non-template class, if declared as a friend,
// will be a friend to all instantiations of the template class
class FriendToAllInstances;

// A non-template function, if declared as a friend,
// will be a friend to all instantiations of the template class
void function();

// Forward declare a template class that we're going to befriend with the Bar
template <typename Type>
class FriendToOneInstance;

// Needed to declare the equality operator
template <typename Type>
class MyClass;

template <typename Type>
bool operator==(const MyClass<Type>&, const MyClass<Type>&);

template <typename Type>
class MyClass
{
	// All instances friendsip
	friend void function();

	// One-to-one friendship (both the operator and the Foo)
	friend class FriendToOneInstance<Type>;
	friend bool operator==<Type>(const MyClass<Type>&, const MyClass<Type>&);
};

int main() {

}

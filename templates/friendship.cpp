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
class OtherClass;

template <typename Type>
bool operator==(const MyClass<Type>&, const MyClass<Type>&);

// Specific instance friend
template <typename Type>
class FriendOnlySpecificInstance;

template <typename Type>
class MyClass
{
	// Friendsip with all instances of MyClass:
	friend void function();

	// Friendship of all instances of MyClass with all instances of OtherClass
	template <typename OtherType> friend class OtherClass;

	// One-to-one friendship (both the operator and the Foo)
	friend class FriendToOneInstance<Type>;
	friend bool operator==<Type>(const MyClass<Type>&, const MyClass<Type>&);

	// Only one instance is a friend of MyClass
	friend class FriendOnlySpecificInstance<int>;
	friend class FriendOnlySpecificInstance<MyClass>;
};

int main() {

}

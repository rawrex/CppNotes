#include <iostream>

// Ex 16.61


template <typename T> class SharedPtr {
	T* ptr;
	void (*deleter)(T*);
	unsigned* counter;
	void cleanup() {
		if (--*counter == 0) {
			//std::cout << "cleanup() b:\ncounter: " << *counter << std::endl;
			if (deleter) {
				deleter(ptr);
				delete counter;
			} else {
				delete ptr;
				delete counter;
			}
		}
	}
public:
	SharedPtr(T* p = nullptr, void(*del)(T*) = nullptr)
		: ptr(p), deleter(del), counter(new unsigned(1)) {}

	SharedPtr(const SharedPtr& p) : ptr(p.ptr), deleter(p.deleter), counter(p.counter) {
		++*counter;
	}
	SharedPtr& operator=(const SharedPtr& rhs) {
		++*rhs.counter;
		cleanup();
		ptr = rhs.ptr;
		counter = rhs.counter;
		deleter = rhs.deleter;
		return *this;
	}
	~SharedPtr() {
		cleanup();
	}
	T& operator*() const {
		return *ptr;
	}
};

template <typename T, void(*deleter)(T*)> class UniquePtr {
	T* ptr;
public:
	UniquePtr(T* p = nullptr) : ptr(p) {}

	UniquePtr(const UniquePtr& p) = delete;
	UniquePtr& operator=(const UniquePtr& p) = delete;
	~UniquePtr() {
		std::cout << "~UniquePtr()" << std::endl;
		deleter(ptr);
	}
};

template <typename T, typename... Args>
auto MakeShared(Args&&... args) -> decltype(T(std::forward<Args>(args)...))* {
	return new T(std::forward<Args>(args)...);
}

void foo(std::string* s) {
	delete s;
}


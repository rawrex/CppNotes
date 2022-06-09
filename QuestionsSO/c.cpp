1. Pass a class A to a function that takes a reference to class B by converting A to B:

void foo(B&);
struct A {
	operator B();
}
A a;
foo(a);

Related:
https://stackoverflow.com/questions/25117970/conversion-operator-with-const


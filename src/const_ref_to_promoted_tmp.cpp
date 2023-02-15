int main() {

	double d = 3.1415;

	// We won't be able bind a non-const reference here
	const int & ir = d;
	
	// This is due the fact that d is converted to int
	// And we then bind the reference to that temporary; as if:
	int tmp = d;
	const int & ir_tmp = tmp;

	// If we were able to bind the non-const reference to the tmp
	// we then would be able to modify the tmp,
	// which would have no effect on the d
	// the variable we would hope to modify through the ir reference.
}

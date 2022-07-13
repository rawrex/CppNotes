#include <iostream>
#include <fstream>

// Each file stream has an associated file mode that represents how the file may be used:
//	in			- open for input
//	out			- open for output
//	app			- append, seek to the end of the file before every write
//	ate			- seek to the end immediately after the open
//	binary		- do IO operations in binary mode
//	trunc		- truncate the file
//
// Note, the underlying values of these modes are implementation defined
// We can supply the file mode whenever we open a file,
// directly (via call to open()) or indirectly (when constructing a file stream).

// The file modes can be supplied with the following restrictions:
//	- "out" may be set only for an ofstream or (a more general) fstream
//	- "in" may be set only for an ifstream or (a more general) fstream
//	- "trunc" may be set only when "out" is also specified 
//	- "app" may be specified as long as "trunc" is not,
//	  if "app" was specified, the the file is always opened in output mode,
//	  even if "out" was not explicitly specified.
//	- by default, a file opened in "out" mode is truncated 
//	  even if we do not specify "trunc".
//	  To preserve contents of a file opened with "out", either we must also specify "app",
//	  in which case we can write only at the end of the file;
//	  Or we must alos specify "in", in which case the file is opened for both input and output.
//	- The "ate" and "binary" modes can be specified on any file stream object type 
//	  and in combination with any other file modes.

// Each file stream has its default file mode.
// "ifstream" files are opened in "in" mode;
// "ofstream" files are opened in "out" mode (note, the contents of the file will be discarded)
// "fstream" files are opened in "in" and "out" mode;

// File streams opened in binary mode perform IO operations independently of any format considerations.
// Non-binary files are known as text files,
// and some translations may occur due to formatting of some special characters 
// (like newline and carriage return characters).

// Discards the contents of the test.file, implicit out and trunc modes
std::ofstream ofile_1("another_test.file");

// Explicit file mode, same as default, trunc is implicit
std::ofstream ofile_2("another_test.file", std::ofstream::out);	

// Explicit file mode, same as default, with explicit trunc< same as default
std::ofstream ofile_3("another_test.file", std::ofstream::out | std::ofstream::trunc);	

// Explicit out, preserve the contents of the file
std::ofstream ofile_4("another_test.file", std::ofstream::out | std::ofstream::app);	

// For the osftream, the default ("out") value is only applied if the function is called 
// without specifying any value for the mode parameter.
// If the function is called with any value in that parameter 
// the default mode is overridden, not combined.
//
// Hence, no implicit "out", explicit "app". Preserve the contents of the file
std::ofstream ofile_5("another_test.file", std::ofstream::app);	

// Print the number in its binary representation
void print(const unsigned long & number)
{
	auto n_bits = 32;
	for (auto i = n_bits; i; --i)
	{
		if(!(i%8))
			std::cout << ' ';
		if(number & (1UL << i))
			std::cout << '1';
		else
			std::cout << '0';
	}
	std::cout << std::endl;
}

int main() {
	
	// Let's see how these modes are defined in our system
	// My system printed the following:
	print(std::fstream::app);		// ... 00000000
	print(std::fstream::ate);		// ... 00000001
	print(std::fstream::binary);	// ... 00000010
	print(std::fstream::in);		// ... 00000100
	print(std::fstream::out);		// ... 00001000
	print(std::fstream::trunc);		// ... 00010000



	// Some examples of calls to open with different modes:

	// Has implicit "trunc" and "out" when we call open()
	std::ofstream test_file;

	// Will avoid discarding the contents
	test_file.open("test.file", std::ofstream::app);

	// Recall that this file stream ctor implicitly calls to the open()
	// So, we actually pass the file mode (implicit or explicit) to this call to open().
	// In fact, the file mode is determined on each call to open()
	// And we can use the same stream with different files and/or different modes.

	// Close the file, so that we can reopen it later with different mode(s)
	test_file.close();

	// Implicit "out", explicit "in", avoid discarding the file contents
	test_file.open("test.file", std::fstream::in);

	// Implicit "in" and explicit "out"
	// "out" may be set only for ofstream or for an fstream objects,
	// So, how come?
	std::ifstream ifile("test.file", std::fstream::out);

}

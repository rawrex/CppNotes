#include "file_modes.h"
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
// (Note, the underlying values of these modes are implementation defined)
//
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
//
// According to the standard when you open an std::ofstream with some mode mode,
// it opens the underlining stream buffer as with mode | ios_base::out.
// Analogously std::ifstream uses mode | ios_base::in.
// std::fstream passes the mode parameter verbatim to the underlining stream buffer, filebuf,
// which one can get through the rdbuf() member function of the stream.
//
// So, the below streams are opened in exactly the same modes:

std::fstream	a("test.file", std::ios_base::in | std::ios_base::out);
std::ifstream	b("test.file", std::ios_base::out);
std::ofstream	c("test.file", std::ios_base::in);

// Do exactly the same things with f.rdbuf(), g.rdbuf() and h.rdbuf(),
// and all the three act as if you opened the file with the C call fopen("a.txt", "r+"),
// which gives you r/w access, does not truncate the file, and fails if the file does not exist.
//
// So, why do we have three different classes?
// Again, these classes are a higher-level interface over the lower-level stream buffer.
// The idea is that std::ifstream has member functions for input, read(),
// std::ofstream has member functions for output, write(),
// while std::fstream has both.

// E.g. we cannot do this:
// b.write("abc", 3);				// error: b does not have a write function

// But this works, since, yet b is an std::ifstream, we've opened it with std::ios_base::out:
// g.rdbuf()->sputn("abc", 3);		// we still have write access



// File streams opened in binary mode perform IO independently of any format considerations.
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

// A utility function used to preserve the contents of the test files
void restoreTestFiles()
{
	std::ofstream test_file("test.file");
	test_file << "foo\nbar\nbaz\nqux quux\n";
	std::ofstream another_test_file("another_test.file");
	another_test_file << "foo\nbar\nbaz\n";
}

void file_modes_main() 
{
	
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


	// What's the difference between these two?
	std::fstream file_a("test.file");
	// Vs.
	std::ofstream file_b("test.file");

	// ofstream::open defaults to openmode ios_base::out,
	// fstream::open defaults to ios_base::in | ios_base::out
	// Also, with std::fstream, an atttempt to open nonexisting file will fail.
	// Unlike, std::ofstream, which creates a file if one cannot be found.
	// We can add the "trunc" to a call to open(), direct or not, on an std::fstream.

	// Implicit "in" and explicit "out"
	// "out" may be set only for ofstream or for an fstream objects,
	// So, how come?
	std::ifstream ifile_test_1("test.file", std::fstream::out);
	// Let's test another one of the restrictions
	// There's no "out" in here, so we should not be able to supply trunc
	std::ifstream ifile_test_2("test.file", std::fstream::trunc);
	// Still can, why? Are the above restrictions are not enforced?

	// Restore the previous contents of the two test files.
	// Ignore this part.
	restoreTestFiles();
}

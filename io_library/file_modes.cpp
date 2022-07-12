#include <iostream>
#include <fstream>

// Each file stream has an associated file mode that represents how the file may be used:
//	in			- open for input
//	out			- open for output
//	app			- append, seek to the end of the file before every write
//	ate			- seek to the end immediately after the open
//	binary		- do IO operations in binary mode
//	trunc		- truncate the file

// We can supply the file mode whenever we open a file, directly or indirectly.

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

// Discards the contents of the test.file, implicit out and trunc modes
std::ofstream ofile_1("another_test.file");

// Explicit file mode, same as default, trunc is implicit
std::ofstream ofile_2("another_test.file", std::ofstream::out);	

// Explicit file mode, same as default, with explicit trunc< same as default
std::ofstream ofile_3("another_test.file", std::ofstream::out | std::ofstream::trunc);	

// Explicit out, preserve the contents of the file
std::ofstream ofile_4("another_test.file", std::ofstream::out | std::ofstream::app);	

// Implicit out, preserve the contents of the file
std::ofstream ofile_5("another_test.file", std::ofstream::app);	


int main() {

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


	

}

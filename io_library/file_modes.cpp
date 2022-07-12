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


int main() {

	std::ofstream ofile;

}

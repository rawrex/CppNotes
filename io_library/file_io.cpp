#include <iostream>
#include <fstream>

void print(const std::string& msg) { std::cout << msg << std::endl; }
const std::string default_filename("test.file");

void readFile(const std::string & filename = default_filename)
{
	// Create a file stream and open the file.
	// Default file mode depends on the type of the stream, thus read-only.
	// The std::string as a filename only since C++11.
	std::ifstream input_file(filename);	
	std::string current_line;

	// We can use the IO operators and getline in the usual way on file streams.
	// As we would have done with any other inherited object where a parent was expected.
	while(std::getline(input_file, current_line))
		print(current_line + '\n');
}

void handleFailedOpen(const std::string & filename)
{
	print("Failed to open file: '" + filename);
	if(input_file_stream.fail())
	{
		print("Failbit is set for the input file stream. Clearing it!");
		// We need to clear the state of the stream before using it further
		input_file_stream.clear();
		print("Calling with the default file.");
		// Note the mutual recursion
		openClose(default_filename);
	}
}

void openClose(const std::string & filename)
{
	std::ifstream input_file_stream;	
	input_file_stream.open(filename);

	// It is usually a good idea to verify that open succeeded
	if(input_file_stream)				
		print("Opened successfully: '" + filename + "'");
	else
		// If a call to open fails, failbit is set
		handleFailedOpen(filename);		
}

void alreadyOpenedFile()
{
	// Trying to open an already opened file will result in failbit set for the file stream.
}
		
	

// In addition to the inherited operations, fstream defines few file specific ones.

int main() {
	// readFile("test.file");
	openClose("nonexistent.file");
}

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


void openClose(const std::string & filename)
{
	std::ifstream input_file_stream;	
	input_file_stream.open(filename);

	// It is usually a good idea to verify that open succeeded
	if(input_file_stream)				
		print("Opened successfully: '" + filename + "'");
	else
		// If a call to open fails, failbit is set
		// And we will need to handle it (clear the state of the stream)
		// Before using it further.
		print("Failed to open file: '" + filename);
}

void openAnotherFileSameStream(std::fstream& fstream, const std::string& new_filename)
{
	// We can associate another file with the same file stream
	// In order to do so we first need to close the existing file,
	// Once it is closed, we can open a new file.
	fstream.close();
	fstream.open(new_filename);
	if(fstream)
		print("Opened a new file for an existing stream. File: '" + new_filename + "'.");
	else
		print("Something wrong with the new file '" + new_filename + "'.");
}

void alreadyOpenedFile()
{
	// Calling open on a file stream that's already open
	// will result in failbit set for the file stream.
	// Thus, in such case, we will need to handle such situation before further processing.

}

		
	

// In addition to the inherited operations, fstream defines few file specific ones.

int main() {
	// readFile("test.file");
	openClose("test.file");
}

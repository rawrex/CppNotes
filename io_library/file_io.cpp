#include <iostream>
#include <fstream>

void print(const std::string& msg) { std::cout << msg << std::endl; }
const std::string test_filename("test.file");
const std::string another_filename("another_test.file");

void readFromFile()
{
	// Create a file stream and open the file.
	// Default file mode depends on the type of the stream, thus read-only.
	// The std::string as a filename only since C++11.
	std::ifstream input_file(test_filename);	
	std::string current_line;

	print("Reading from file: '" + test_filename + "':");

	// We can use the IO operators and getline in the usual way on file streams.
	// As we would have done with any other inherited object where a parent was expected.
	while(std::getline(input_file, current_line))
		print(current_line);
}


void openClose()
{
	std::ifstream ifstream;	
	ifstream.open(test_filename);			// Explicitly open a file for this file stream
	if(test_filename)						// It is usually a good idea to verify that open succeeded
		print("Opened successfully: '" + test_filename + "'");
	else
		// If a call to open fails, failbit is set
		// And we will need to handle it (clear the state of the stream)
		// Before using it further.
		print("Failed to open file: '" + test_filename);
}

void openAnotherFileSameStream()
{
	// We can associate another file with the same file stream
	// In order to do so we first need to close the existing file,
	// Once it is closed, we can open a new file.

	std::fstream fstream(test_filename);	// Create a stream and associate it with a file
	fstream.close();						// Close the associated file
	fstream.open(another_filename);			// Reopen a new file with the same stream

	if(fstream)
		print("Opened a new file for an existing stream. File: '" + another_filename + "'.");
	else
		print("Something wrong with the new file.");

	// Note, we cannot extract the current filename for the stream.
	// The underlying file may have several names (if it has multiple hard links)
	// Or no name at all (if it represents an anonymous pipe, for instance)
}

void alreadyOpenedFile()
{
	// Calling open on a file stream that's already open
	// will result in failbit set for the file stream.
	// Thus, in such case, we will need to handle such situation before further processing.

	std::fstream fstream;				// Create a file stream, no file is associated.
	fstream.open(test_filename);		// Explicitly associate a file with the file stream
	fstream.open(test_filename); 	// Second call to open will set the failbit,
										// Rendering the stream unusable for now
	if(fstream.fail())
	{
		print("Tried to call open for a stream which already has an opened file. Failbit is set.");
		fstream.clear();
		print("Cleared the failbit for the stream.");
	}
}

void closeClosedFile()
{
	// We can close a file stream more than once. No error.
	std::fstream file(test_filename);
	file.close();
	file.close();
}
		
int main() {
	
	// Read from file and print its contents line by line
	readFromFile();

	// Open a file, checking if it is ok to open it
	openClose(test_filename);

	// Open a file for this stream to open another file for it later
	openAnotherFileSameStream();

	// Try to call open on an "opened" file stream, fail, clear the state
	alreadyOpenedFile();

	// Try to use the stream again
	openAnotherFileSameStream();

	// Double close
	closeClosedFile();
}

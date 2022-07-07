#include <iostream>
#include <fstream>

void print(const std::string& msg) { std::cout << msg << std::endl; }
const std::string test_filename("test.file");
const std::string another_filename("another_test.file");

void readFile(const std::string & filename = test_filename)
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
	std::fstream fstream(test_filename);
	fstream.close();
	fstream.open(new_filename);
	if(fstream)
		print("Opened a new file for an existing stream. File: '" + new_filename + "'.");
	else
		print("Something wrong with the new file '" + new_filename + "'.");

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
	// readFile("test.file");
	openClose(test_filename);

	// Open a file for this stream to open another file for it later
	std::fstream ifile("test_2.file");	
	openAnotherFileSameStream(ifile, test_filename);

	// Try to call open on an "opened" file stream, fail, clear the state
	alreadyOpenedFile();

	// Try to use the stream again
	openAnotherFileSameStream(ifile, test_filename);

	closeClosedFile();
}

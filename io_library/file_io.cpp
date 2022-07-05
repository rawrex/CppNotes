#include <iostream>
#include <fstream>



void readFile(const std::string & filename)
{
	// Create a file stream and open the file
	// Default file mode depends on the type of the stream, thus read-only
	std::ifstream input_file(filename);
	std::string current_line;

	// We can use the IO operators and getline in the usual way on file streams
	while(std::getline(input_file, current_line))
		std::cout << current_line << '\n';
}

// In addition to the inherited operations, fstream defines few file specific ones.

int main() {
	readFile("test.file");
}

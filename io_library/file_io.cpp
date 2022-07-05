#include <iostream>
#include <fstream>

void readFile(const std::string & filename)
{
	// Create a file stream and open the file
	std::ifstream input_file(filename);
	std::string current_line;

	// We can use the IO operators and getline in the usual way on file streams
	while(std::getline(input_file, current_line))
		std::cout << current_line << '\n';
}

int main() {

	readFile("test.file");
		
}

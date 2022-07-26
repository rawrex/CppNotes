#include <iostream>
#include <string>

void print(const std::string& msg)
{
	std::cout << msg << std::endl;
}


// We can use these for speed, but they are error-prone.
// They require us to allocate and manage the character arrays as buffers.
//
// input_stream.get(sink, size, delimiter);		reads bytes up to the "size" from "input_stream"
//												stores them in the char.array beginning at the address
//												pointed to by the "sink";
//												reads until "size", "delimiter", or EOF is met;
//												if "delimiter" is present, it is left on the stream 
//
// input_stream.getline(sink, size, delim);		same as above, but reads and discards the "delim"
//
// input_stream.read(sink, size);				reads up to "size" bytes into the character array "sink";
//												returns "input_stream"
//
// input_stream.gcount();						returns the number of bytes read from the "input_stream"
//												by the last call to an unformatted read operation
//
// input_stream.ignore(size, delimiter);		reads and ignores at most "size" characters up to,
//												up to (not including) "delimiter";
//												unline other operations, has default arguments:
//												"size" = 1, "delimiter" = EOF
//
// output_stream.write(source, size);			writes "size" bytes from the character array "source"
//												into "output_stream"; 
//												returns "output_stream"


void get_example()
{
	constexpr size_t size = 5;
	char buffer[size];
	const char delim = 'x';

	// Get characters from the stdin, until we get four or an 'x'
	// Note, whitespace counts too
	std::cin.get(buffer, size, delim);

	print("write:");
	std::cout.write(buffer, size);
}
	
void getline_example()
{
	constexpr size_t size = 5;
	char buffer[size];
	const char delim = 'x';

	// Get characters from the stdin, until we get four or an 'x',
	// Then read the fifth character and discard it from the stream
	// Note, whitespace counts too
	std::cin.getline(buffer, size, delim);

	print("write:");
	std::cout.write(buffer, size);
}

int main() {

	print("get:");
	get_example();

	print("getline:");
	getline_example();

}

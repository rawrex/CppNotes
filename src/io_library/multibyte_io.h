#include <iostream>
#include <string>

void print(const std::string& msg)
{
	std::cout << msg << std::endl;
}


// We can use these for speed, but they are error-prone.
// They require us to allocate and manage the character arrays as buffers.

// input_stream.get(sink, size, delimiter);		reads characters up to the "size" from "input_stream"
//												stores them in the character array beginning at the address
//												pointed to by the "sink";
//												reads until "size", "delimiter", or EOF is met;
//												if "delimiter" is present, it is left on the stream 

// input_stream.getline(sink, size, delim);		same as above, but reads and discards the "delim"

// input_stream.read(sink, size);				reads up to "size" bytes into the character array "sink";
//												returns "input_stream"

// input_stream.gcount();						returns std::streamsize type,
//												with the number of bytes read from the "input_stream"
//												by the last call to an unformatted read operation,
//												or the maximum representable value of std::streamsize 
//												if the number is not representable.
//
// The following member functions of basic_istream change the value of subsequent gcount() calls:
//		- move constructor
//		- swap()
//		- get()
//		- getline()
//		- ignore()
//		- read()
//		- readsome()
//		- operator>>(basic_streambuf*) 
//
// The following functions set gcount() to zero:
//		- constructor
//		- putback()
//		- unget()
//		- peek()
//
// So, note, it is essential to call gcount() before any of these operations for it to return the intended value.

// input_stream.ignore(size, delimiter);		reads and ignores at most "size" characters up to,
//												up to (not including) "delimiter";
//												unline other operations, has default arguments:
//												"size" = 1, "delimiter" = EOF

// input_stream.readsome(sink, size);			Extracts up to "size" immediately available characters from the input_stream.
//												The extracted characters are stored into the character array pointed to by "sink".
//												The behavior is highly implementation specific.
//												E.g.
//												We can observe the difference between read() and readsome() 
//												on a flash filing system.								

// output_stream.write(source, size);			writes "size" bytes from the character array "source"
//												into "output_stream"; 
//												returns "output_stream"

// Note, it is not uncommon to forget to remove the delimitre from the stream


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

void read_example()
{
// While get() would be more appropriate on a text stream
// read() is more appropriate action on a binary datasource,
// reading a specific number of bytes.

	constexpr size_t size = 5;
	char buffer[size];

	std::cin.read(buffer, size);

	print("write:");
	std::cout.write(buffer, size);
}
	
void gcount_example()
{
	get_example();
	std::cout << "gcount: " << std::cin.gcount() << std::endl;
}

void ignore_basic_example()
{
	std::string str;
	constexpr size_t size = 3;
	std::cin.ignore(size, 'X');
	std::cin >> str;
	std::cout << str << std::endl;
}
void ignore_useful_example()
{
	// One the most common uses for the ignore()
	// is to discard the newline character before a call to getline()
	// that is left after a formatted input.
	char ch = ' ';
	std::string line;

	std::cin >> ch;
	
	// Now, since we've pressed the Enter, there's a newline left in the buffer
	// And if we were to call getline() right now, it will see the '\n' first of all
	// The '\n' will be discarded, but the input operation will stop immediately.
	// std::getline(std::cin, line);
	std::cin.ignore();
	std::getline(std::cin, line);
	std::cout << ch << ' ' << line << std::endl;

	// Another way to discard the whitespace is to use the std::ws manipulator 
	// whici is designed to extract and discard leading whitespace from the beginning of an input stream:
	// std::cin >> std::ws returns the std::cin itself:
	// std::getline(std::cin >> std::ws, name);

	// Note, the call to the manipulator changes the state of the stream
	// So, the manipulator will be in effect for any consequent operations.

	// In general, we should avoid combining formatted input operations (operator>>())
	// With unformatted input operations.
	// Unformatted input operations are anything other than that,
	// like std::getline(), std::cin.read(), std::cin.get(), etc
}

void multibyte_io_main() 
{

//	print("get:");
//	get_example();

//	print("getline:");
//	getline_example();

//	print("read:");
//	read_example();

//	print("get + gcount");
//	gcount_example();

//	print("ignore example");
//	ignore_basic_example();

	print("ignore useful example");
	ignore_useful_example();
}

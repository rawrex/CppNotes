#include <iostream>
#include <sstream>
#include <vector>

// The sstream header defined types which we can use to do in-memory IO
// These types read and write to an underlying std::string as if it was an IO stream.

// At the low level,
// the class essentially wraps a raw string device implementation of std::basic_stringbuf
// into a higher-level interface of std::basic_iostream.

// There are two specializations for common character types are also defined:
//	- stringstream 		basic_stringstream< char >
//	- wstringstream 	basic_stringstream< wchar_t >

// We have the std::istringstream which reads a string;
// The std::ostringstream which writes to a string;
// And the std::stringstream which does both.

// These types inherit from the iostream header types (just like fstream).
// These types also introduce some specific operations as well (just like fstream).



// We most often use input sstream when we want to get a line as a whole
// And then operate on its contents.

void example_istringstream()
{
	// Our custom data type
	struct Widget
	{
		std::string id;
		std::vector<std::string> aliases;
	};
	std::vector<Widget> data;
	std::string line;
	std::string word;

	// Get input from a user and fill the data container accordingly
	while(getline(std::cin, line))
	{
		Widget widget;
		std::istringstream iss(line);			// Prepare the sstream, copy the line into it
		iss >> widget.id;						// Get the id from the stream first
		while(iss >> word)						// Then get all the aliases
			widget.aliases.push_back(word);

		data.push_back(widget);
	}

	// Print the contents of the now populated data
	for (const auto& wid : data)
	{
		std::cout << wid.id << std::endl;
		for (const auto& alias : wid.aliases)
			std::cout << alias << ' ';
		std::cout << std::endl;
	}
}


// We most often use output sstream when we want to accumulate some data
// And then print it as a whole
				

void string_basics_main() 
{

	std::string string_a("Foo bar");
	std::stringstream string_stream(string_a);		// Holds a copy of the str, this ctor is explicit

	std::string string_b = string_stream.str();		// Returns a copy of the internal string

	std::string string_c("Baz qux");
	string_stream.str(string_c);					// Copies string into the stream, returns void

	example_istringstream();

}

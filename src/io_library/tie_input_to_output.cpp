#include <iostream>
#include <chrono>
#include <thread>
	
int sleep_time = 3;

void sleep(unsigned duration = sleep_time)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

// The std::stream::tie manages the tied stream, an output stream which is synchronized
// with the sequence controlled by the stream buffer (rdbuf()),
// that is, flush() is called on the tied stream before any input/output operation on *this.
//
// The library, by default, ties cout to cin.

// There are two overloads fot the tie:
//	- Takes no arguments
//	- Takes a pointer to an ostream and ties itself to that stream
//
// Multiple streams can tie themselves to the same output stream.
// But each stream can be tied to at most one stream at a time.


void printToTiedStream()
{
	std::ostream* current_stream = std::cin.tie();
	// Dereference the pointer and send output to the stream
	*current_stream << "Print to the stream to which the std::cin is tied now.\n";
}
void untieShowcase()
{
	int input = 0;

	// Untie the std::cin from the std::cout
	std::cin.tie(nullptr);

	std::cout << "(Isn't guaranteed to be printed)\nYour input: ";
	std::cin >> input;

	// Tie the input stream back to the std::cout
	std::cin.tie(&std::cout);
	
}

void cantRely()
{
	int answer = 0;

	// Note, that sometimes we need to explicitly manage the flushing
	// Even tought the output buffer will be flushed before the input
	// Here, it will be too late, since the timed prompt won't function as we intend it to:
	std::cout << "Multiply 9 by 13, I generously give you " << sleep_time << " sec. to think... ";
	sleep();

	// This will be printed (along with the print above) right before the request for input
	std::cout << "Ok! Time's up! Your answer: ";
	std::cin >> answer;		// Sudden answer request
	// ...
}

int main() {

	printToTiedStream();
	untieShowcase();
	cantRely();
	
}

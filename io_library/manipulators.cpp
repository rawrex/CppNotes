#include <iostream>
#include <chrono>
#include <thread>

void sleep(unsigned duration = 3)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

int main() {

	// Since our std::cout goes to a terminal, it is (usually) line buffered.
	// If we were to direct the std::cout to a pipe, file, or some other non-interactive destination,
	// the endl forces the data out even if the stream is fully buffered, as it usually will be.
	// Thus, we place \n in the line where we already have flush requests.

	// Ends the current line and flushes the buffer
	std::cout << "endl" << std::endl;	// No need for \n at the end of the message
	std::cout << "...had no manipulators, printed with the next flush";
	sleep();

	// Flushes the stream but does not adds any characters to the output
	std::cout << "\nflush\n" << std::flush;
	std::cout << "...had no manipulators, printed with the next flush";
	sleep();

	// Inserts a null character into the buffer and then flushes it
	std::cout << "\nends\n" << std::ends;
	std::cout << "...had no manipulators, printed with the next flush";
	sleep();

	// Modify the internal state of the stream. Flush the stream on every output operation
	std::cout << std::unitbuf;
	std::cout << "\nunitbuf\n";
	std::cout << "...had no manipulators, but printed immediately";
	sleep();

	// Restore the state of the stream to the system-managed buffer flushing:
	std::cout << std::nounitbuf;
	std::cout << "\nnounitbuf\n";
	std::cout << "...had no manipulators, printed on the program termination";
	std::cout << '\n';
	sleep();

	// Note, if a program crashes, there can be data sitting in a buffer.
	// Make sure to flush the buffer when debug.

}

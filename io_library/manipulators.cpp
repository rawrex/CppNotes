#include <iostream>
#include <chrono>
#include <thread>

void sleep(unsigned duration = 3)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

int main() {

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

}

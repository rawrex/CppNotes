#include <iostream>
#include <chrono>
#include <thread>

void sleep(unsigned duration)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

// The std::stream::tie manages the tied stream, an output stream which is synchronized
// with the sequence controlled by the stream buffer (rdbuf()),
// that is, flush() is called on the tied stream before any input/output operation on *this.
//
// The library, by default, ties cout to cin.

void weCantRelyOnItAlways()
{
	int answer = 0;
	int sleep_time = 3;

	// Note, that sometimes we need to explicitly manage the flushing
	// Even tought the output buffer will be flushed before the input
	std::cout << "Multiply 9 by 13, I generously give you " << sleep_time << " sec. to think... ";
	sleep(sleep_time);

	// This will be printed (along with the print above) right before the request for input
	std::cout << "Ok! Time's up! Your answer: ";
	std::cin >> answer;		// Sudden answer request
	// ...
}

int main() {

	weCantRelyOnItAlways();
	
}

#include <iostream>
//#include <unistd.h>
#include <chrono>
#include <thread>

// The OS might store the data sent to the output stream in a buffer
// and then combine several output operations in one system level wirte as a preformance optimizaiton.
// 
// There are several conditions that cause the buffer to be flushed:
//	1. The program completes (normally). All output buffers are flushed on the return from main()
//	2. Buffer may become full, in which case it must be flushed before the next write to it
//	3. We can explicitly flush the buffer, using the stream manipulators
//	4. We can use the unitbuf manipulator to set the stream's internal state
//	   to empty the bufffer after each operation.
//	   The unitbuf is set for std::cerr, so writes to it are written immediately.
//	5. An output stream may be tied to another stream.
//	   If so, the output stream is flushed every time the stream it tied to is read or written.

unsigned int microsecond = 1000000;
unsigned sleep_duration = 3;

void sleep(unsigned duration)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}
	

int main() {
	// Explicitly make sure we print Foo before sleeping
	std::cout << "Foo!" << std::flush;

	// No guarantee the Bar will be printed before the sleep
	std::cout << "\nBar!";
	
	// Sleep
	sleep(sleep_duration);

	// Or via syscall
	// usleep(sleep_duration * microsecond);

	std::cout << "\nBaz!\n";
}

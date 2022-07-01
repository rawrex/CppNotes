#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

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

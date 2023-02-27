#include "utils.h"
#include <iostream>
#include <thread>

void IOLibrary::sleep(unsigned duration)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

void IOLibrary::print(const std::string& msg)
{
	std::cout << msg << std::endl;
}

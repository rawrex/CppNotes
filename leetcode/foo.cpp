#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

void printvec(const std::vector<int>& vec) 
{
	size_t count = 0;
	for (const auto & i : vec)
	{
		if (i != -1)
			std::cout << count << std::endl;
		count++;
	}
	std::cout << std::endl;
}

size_t solve(const std::string& str)
{
	size_t n = str.size();
	if (!n) return 0;

	int open_i = 0, close_i = 1, window_size = 0;
	int max_length = 1, largest_open_i = 0, largest_close_i = 1;

	std::vector<int> prev_occurence(256, -1);

	prev_occurence[str[0]] = 0;
	printvec(prev_occurence);

	while (close_i < n)
	{
		if (prev_occurence[str[close_i]] >= open_i)
			open_i = prev_occurence[str[close_i]] + 1;

		prev_occurence[str[close_i]] = close_i;
		close_i++;

		printvec(prev_occurence);

		window_size = close_i - open_i;

		if (window_size > max_length)
		{
			max_length = window_size;
			largest_open_i = open_i;
			largest_close_i = close_i;
		}
	}
	return max_length;
}

int main() {
	std::string str = "aabaab!bb";
	solve(str);
}

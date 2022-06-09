#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

struct Foo {
	int operator()(bool boo, int x, int y) {
		int ret = boo ? x : y; 
		return ret;
	}
};

class ReadString {
public:
	std::istream& operator()(std::string& s, std::istream& is = std::cin) {
		std::cout << "Enter: ";
		getline(is, s);
		if (!is)
			s = std::string();
		return is;
	}	
};

class ReplaceWith {
		std::string old_value;
		std::string new_value;
public:
		ReplaceWith(const std::string& o, const std::string& n = std::string()) 
				: old_value(o), new_value(n) {}
		void operator()(std::string& current) {
			if (current == old_value)
					current = new_value;
		}
};

class ShorterThan {
	std::size_t limit;
public:
	ShorterThan(const std::size_t& lim) : limit(lim) {}
	bool operator()(const std::string& s) {
		return s.size() <= limit;
	}
};

size_t count_file(const std::string& filename, const std::size_t& sz) {
	std::fstream inf(filename, std::ifstream::in);
	std::string word;
	std::vector<std::string> words;
	while (inf >> word)
		words.push_back(word);
	inf.close();
	return std::count_if(words.cbegin(), words.cend(), ShorterThan(sz));
}

int main() {
	std::vector<std::string> vs {"ab", "abcde", "abc", "abcdefghi", "abcde", "abcdef"};
	std::cout << count_file("foo.txt", 3) << std::endl;
}

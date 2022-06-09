#include <map>
#include <functional>
#include <iostream>

std::map<char, std::function<int(int,int)>> ops {
		{'+', [](int a, int b){return a+b;}},
		{'-', [](int a, int b){return a-b;}},
		{'*', [](int a, int b){return a*b;}},
		{'/', [](int a, int b){return a/b;}}};

int main() {
		std::cout<<ops['-'](10,4) << std::endl;
}

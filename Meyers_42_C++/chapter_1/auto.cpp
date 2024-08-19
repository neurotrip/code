#include <iostream>

int main()
{
	auto x = 5;
	auto y = x  + 1.1;
	x = y;
	std::cout << x << std::endl;
	auto word = "word";
	std::cout << word << std::endl;
	return 0;
	
}


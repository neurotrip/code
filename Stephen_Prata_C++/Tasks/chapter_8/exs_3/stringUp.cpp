#include <cstddef>
#include <iostream>
#include <string>
#include <cctype>

void StringUp(std::string &str);

int main()
{
	std::string str;
	
	std::cout << "Enter a string (q to quit): ";
	std::getline(std::cin, str);
	for(;;) {
		if (str == "q")
			break;
		else 
			StringUp(str);	
		std::cout << str << std::endl;
		std::cout << "Next string (q to quit): ";
		std::getline(std::cin, str);
	}
	std::cout << "Bye\n";
	return 0;
}

void StringUp(std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i) 
		str[i] = std::toupper(str[i]);
}


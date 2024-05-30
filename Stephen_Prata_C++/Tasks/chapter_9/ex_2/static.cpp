#include <iostream>
#include <string>

const int ArSize = 10;

void strcount(std::string str);

int main()
{
	using namespace std;
	string input;
	cout << "Enter a line: \n";
	getline(cin, input);
	while(input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}

void strcount(std::string str)
{
	using namespace std;
	static int total = 0;
	int count = 0;
	cout << "\"" << str << "\" contains";
	for (size_t i = 0; i < str.length(); ++i)
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}


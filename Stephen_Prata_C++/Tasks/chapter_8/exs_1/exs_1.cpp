#include <iostream>

using namespace std;
void PrintString(const char *str, int n = 0);

int main()
{
	const char * str = "LINUX!";
	int count = 0;
	char choice;
	
	do {
		cout << "Вызвать функцию?\n";
		cin >> choice;
		PrintString(str);
		count++;
	} while (choice != 'n');
	
		
	PrintString(str, count);

	return 0;
}

void PrintString(const char *str, int n)
{
	if (n != 0) {
		for (int i = 0; i < n; i++) 
			cout << str << endl;
	} else 
		cout << str << endl;

}

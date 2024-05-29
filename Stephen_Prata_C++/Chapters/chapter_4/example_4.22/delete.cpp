#include <iostream>
#include <cstring>
using namespace std;
char * getname(void);

int main()
{
	char * name;
	name = getname();
	cout << name << " at " << static_cast<void *>(name) << "\n";
	delete [] name;
	name = getname();
	cout << name << " at " <<  static_cast<void *>(name) << "\n";
	delete [] name;
	return 0;
}

char *getname()
{
	char temp[80];
	cout << "Enter last name: ";
	cin.getline(temp, 80);
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	cout << pn << " at " << static_cast<void *>(pn) << "\n";
	return pn;
}


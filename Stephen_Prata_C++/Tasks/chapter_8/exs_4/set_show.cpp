#include <iostream>
#include <cstring>
using namespace std;

struct stringy {
	char *str;
	int ct;
}; 

void set(stringy &str, char *phrase);
void show(stringy &str, int n = 1);
void show(char *str, int n = 1);
void show(const char *str);

int main()
{
	stringy beany;
	char testing[] = "Reality king.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	return 0;
}

void set(stringy &str, char *phrase) 
{
	char *p = new char [strlen(phrase)];
	str.str = p;
	strcpy(p, phrase);
	str.ct = strlen(p);
}

void show(stringy &str, int n)
{
	for (int i = 0; i < n; i++) 
		cout << str.str << endl;
}

void show(char *str, int n)
{
	for (int i = 0; i < n; i++)
		cout << str << endl;
}

void show(const char *str)
{
	cout << str << endl;
}




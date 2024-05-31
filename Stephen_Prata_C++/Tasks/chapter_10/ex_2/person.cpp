#include <iostream>
#include "person.h"
#include <cstring>

Person::Person()
{
	lname = "";
	fname[0] = '\0';
}

Person::Person(const std::string &ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
}

void Person::Show() const 
{
	std::cout << "Last name: " << lname << "\n";
	std::cout << "First name: " << fname << "\n";
}

void Person::FormalShow() const
{
	std::cout << "First name: " << fname << "\n";
	std::cout << "Last name: " << lname << "\n";
}

	

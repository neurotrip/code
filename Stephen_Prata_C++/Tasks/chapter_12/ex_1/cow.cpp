#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow() 
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
	strncpy(name, nm, 20);
	name[19] = '\0';
	hobby = new char[(strlen(ho)) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow &c) 
{
	hobby = new char[(strlen(c.hobby)) + 1];
	strcpy(name, c.name);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow &c)
{
	if (this == &c)
		return *this;
	delete [] hobby;
	hobby = new char [(strlen(c.hobby)) + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const 
{
	std::cout << "Name: " << name << "\n";
	std::cout << "Hobby: " << hobby << "\n";
	std::cout << "Weight: " << weight << "\n";
}


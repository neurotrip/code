#include <iostream>
#include "plorg.h"
#include <cstring>

Plorg::Plorg(const char *name, int CI)
{
	strncpy(name_, name, LEN);
	CI_ = CI;
}

void Plorg::set_CI(int CI)
{
	CI_ = CI;
}

void Plorg::show()
{
	std::cout << "Name: " << name_ << "\n";
	std::cout << "CI: " << CI_ << "\n";
}



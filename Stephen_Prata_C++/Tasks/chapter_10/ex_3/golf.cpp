#include <iostream>
#include "golf.h"
#include <cstring>

Golf::Golf(const char *name, int hc) 
{
	strcpy(fullname_, name);
	handicap_ = hc;
}

Golf::Golf()
{
	std::cout << "Enter the player`s name: ";
	std::cin >> fullname_;
	std::cout <<"Enter the player's handicap: ";
	std::cin >> handicap_;
}

void Golf::handicap(int hc)
{
	handicap_ = hc;
}

void Golf::showgolf()
{
	std::cout << "Name: " << fullname_ << std::endl;
    std::cout << "Handicap: " << handicap_ << std::endl;
}




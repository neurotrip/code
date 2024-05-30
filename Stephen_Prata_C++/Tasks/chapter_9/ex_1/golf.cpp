#include <iostream>
#include "golf.h"
#include <cstring>
#include <limits>
void setgolf(golf &g, const char *name, int hc)
{
	strcpy(g.fullname,name);
	g.handicap = hc;
}

int setgolf(golf &g) 
{
	std::cout << "Enter the player's name: ";
	std::cin >> g.fullname;
    if (strlen(g.fullname) == 0)
        return 0;
    std::cout << "Enter the player's handicap: ";
    std::cin >> g.handicap;
//    std::cin.get(); 
    return 1;
}

void handicap(golf &g, int hc) 
{
	g.handicap = hc;
}

void showgolf(const golf &g) 
{
	std::cout << "Name: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}


				

#include <iostream>
#include "wine.h"

Wine::Wine() 
	: label("unknown"), years(0), data(ArrayInt(), ArrayInt()) 
{
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
	: label(l), years(y), data(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char *l, int y)
	: label(l), years(y), data(ArrayInt(y), ArrayInt(y)) 
{
}

void Wine::GetBottle()
{
	std::cout << "Enter " << years << "pair of years and bottle\n";
	for (int i = 0; i < years; i++) {
		std::cout << "Years:\n";
		std::cin >> data.getYears()[i];
		std::cout << "Bottles:\n";
		std::cin >> data.getBottles()[i];
	}
}

std::string Wine::Label() const 
{
	return label;
}

int Wine::sum() 
{
	return data.getBottles().sum();
}

void Wine::Show() const 
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "     Year" << "     Bottles\n";
	for (int i = 0; i < years; i++) {
		std::cout << "     " << data.getYears()[i] 
				  << "     " << data.getBottles()[i] << std::endl;
	}
}





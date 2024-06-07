#include <iostream>
#include "cow.h"

int main()
{
	Cow cow1;
	Cow cow2("Korova", "Trava", 12);
	Cow cow3("Byrenka", "Moloka", 13);

	std::cout << "cow1: "<< std::endl;
	cow1.ShowCow();
	std::cout << "cow2: "<< std::endl;
	cow2.ShowCow();
	std::cout << "cow3: "<< std::endl;
	cow3.ShowCow();
	std::cout <<"\n";
	return 0;
}	

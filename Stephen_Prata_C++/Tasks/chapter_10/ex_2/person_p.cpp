#include <iostream>
#include "person.h"

int main()
{
	Person one;
	Person two("Smythecraft");

	Person three("Dimwiddy", "Sam");
	
	std::cout << "First\n";
	one.Show();
	std::cout << std::endl;
	one.FormalShow();
	std::cout <<"Two\n";
	two.Show();
	std::cout<< std::endl;
	two.FormalShow();
	std::cout <<"Three\n";
	three.Show();
	std::cout << std::endl;
	three.FormalShow();

	return 0;
}


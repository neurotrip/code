#include <iostream>
#include "string1.h"


int main()
{
	String str1("opa");
	String str2("ppp");
	String sum;
   	sum	= str1 + str2;

	std::cout << sum << std::endl;
	str1.to_lower();
	std::cout << str1 << std::endl;
	str2.to_upper();
	std::cout << str2 << std::endl;
	std::cout << sum.How('p') << std::endl;
	return 0;
}



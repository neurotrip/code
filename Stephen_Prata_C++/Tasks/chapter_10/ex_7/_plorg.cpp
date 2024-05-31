#include <iostream>
#include "plorg.h"

int main()
{
	Plorg plorg1;
	Plorg plorg2("Mark Zuckerberg", 777);
	plorg1.set_CI(88);
	plorg1.show();
	plorg2.show();

	return 0;
}


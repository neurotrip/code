#include <iostream>
#include "port.h"

int main()
{
	Port p1("Tri topora", "Red", 7);
	VintagePort vp1("ARARAT", 8, "armenian", 1988);
	p1.Show();
	vp1.Show();
	std::cout << "After +=: " << std::endl;
	p1 += 1;
	std::cout << p1.BottleCount() << std::endl;
	std::cout << "After -=: " << std::endl;
	p1 -= 2;
	std::cout << p1.BottleCount() << std::endl;
	p1.BottleCount();
	VintagePort vp2;
	vp2 = vp1;
	vp2.Show();
	VintagePort vp3;
	vp3.Show();
	std::cout << vp3.BottleCount() << std::endl;
	return 0;
}


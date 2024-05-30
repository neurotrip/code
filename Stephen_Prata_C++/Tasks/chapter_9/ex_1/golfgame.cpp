#include <iostream>
#include "golf.h"

int main() 
{
	golf player[3];
	

	for(int i = 0; i < 3; i++) {
		std::cout<<"Enter player: \n";
		setgolf(player[i]);
	}
	
	setgolf(player[0], "Mark Zuckerberg", 24);
	handicap(player[1], 88);

	for (int i = 0; i < 3; i++) {
		std::cout <<"Players data: \n";
		showgolf(player[i]);
		std::cout << std::endl;
	}

	return 0;
}


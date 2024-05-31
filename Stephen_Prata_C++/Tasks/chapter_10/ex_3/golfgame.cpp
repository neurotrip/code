#include <iostream>
#include "golf.h"

int main()
{
    Golf player[3] = {
		Golf(),
		Golf("Mark Zuckerberg", 24),
		Golf()
	};

	player[0].handicap(1488);

	for (int i = 0;	i < 3; i++) {
		player[i].showgolf();
	}



    return 0;
}


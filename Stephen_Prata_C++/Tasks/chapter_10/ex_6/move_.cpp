#include <iostream>
#include "move.h"

int main()
{
	Move dot1(1, 1);
	Move dot2 = dot1.add(dot2);
	dot1.showmove();
	dot2.showmove();
//	dot1.reset();
	dot2.reset();
	dot1.showmove();
	dot2.showmove();
	dot1 = dot1.add(dot1);
	dot1.showmove();

	return 0;
}	

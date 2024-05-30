#include <iostream>
#include <cstring>

struct chaff {
	char dross[20];
	int slag;
};

static char buffer[512];

int main()
{
	chaff *array = new (buffer) chaff[2];
	
	for (int i = 0; i < 2; i++) {
	   strcpy(array[i].dross, "lopay");
	   array[i].slag = 12;
	}
	
	for (int i = 0; i < 2; i++) {
		std::cout <<"Dross: " << array[i].dross << std::endl;
		std::cout <<"Slag: " << array[i].slag << std::endl;
	}

	return 0;
}

		
   	 		   


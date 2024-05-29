#include <iostream>

template <typename T>
T max5(T array[]);

int main()
{
	int ar1[] = {1,3,4,7,9};
	double ar2[] = {1.1, 3.3, 6.5, 6.4, 4,1};

	std::cout << max5(ar1) << std::endl;
	std::cout << max5(ar2) << std:: endl;

	return 0;
}

template <typename T>
T max5(T array[]) 
{
	T max = array[0];
	for (int i = 0; i < 5;i++) {
		if (max < array[i])
			max = array[i];
	}
	return max;
}



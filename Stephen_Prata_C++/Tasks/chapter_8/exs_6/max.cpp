#include <iostream>
#include <cstring>

template <typename T>
T maxn(T array[], int n);
template <> const char *maxn(const char *ar[], int n);

int main()
{
    int ar1[] = {1,3,4,7,9,4};
    double ar2[] = {1.1, 3.3, 6.5};
	const char *ar3[6] = {"Holy", "Unded", "God","Dark", "Angel", "Evil"}; 

    std::cout << maxn(ar1, 6) << std::endl;
    std::cout << maxn(ar2, 4) << std::endl;
	std::cout << maxn(ar3, 6) << std::endl;
    return 0;
}

template <typename T>
T maxn(T array[],int n)
{
    T max = array[0];
    for (int i = 0; i < n;i++) {
        if (max < array[i])
            max = array[i];
    }
    return max;
}

template <> const char *maxn(const char *ar[], int n) 
{
	const char **p = ar;
	for (int i = 0; i < n; i++) {
		if (strlen(*p) < strlen(ar[i]))
			*p = ar[i];
	}

	return *p;
}

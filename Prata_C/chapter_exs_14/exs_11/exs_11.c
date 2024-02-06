#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void transform(double source[], double target[], int max, double (*fun)(double));
double squad(double a);
double hack(double a);
int main()
{
	double array_1[100];
	double array_2[100];
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		array_1[i] = (double)rand() / (RAND_MAX + 1.0);
	}
	
	transform(array_1, array_2, 100, sin);
	transform(array_1, array_2, 100, cos);
	transform(array_1, array_2, 100, squad);
	transform(array_1, array_2, 100, hack);
	return 0;
}

void transform(double source[], double target[], int max, double (*fun)(double)) 
{
	printf("Вызов функции\n");
	int rows = 10;
	for (int i = 0; i < rows; i++) { 
    	for (int j = 0; j < 10; j++) { 
 			int index = j * rows + i; 
            if (index < 100) { 
                target[index] = fun(source[index]); 
                printf("%9.4f ", target[index]); 
            }
        }
        printf("\n"); 
    }	
}

double squad(double a)
{
	return (sin(a) / cos(a)) / a  ;
}

double hack(double a)
{
	return ((a * a * a) / a ) / (a + a);  
} 



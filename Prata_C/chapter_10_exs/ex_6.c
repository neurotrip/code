#include <stdio.h>
#define FMAS 3
#define SMAS 5
void coppy_arr(const int str, const int col, double ar1[str][col], double ar2[str][col]);
void coppy_ptr(const int str, const int col, double (*ar1)[col], double (*ar2)[col]);

int main(void)
{
        double source[FMAS][SMAS] =  {
	{1.3, 2.2, 3.4, 4.4, 5.5},
	{1.1, 2.3, 3.1, 4.2, 5.2},
	{1.5, 2.5, 3.6, 4.1, 5.8}
	};

        double target1[FMAS][SMAS];
        double target2[FMAS][SMAS];
        int i, j;
        coppy_arr(FMAS, SMAS, source, target1);
        coppy_ptr(FMAS, SMAS, source, target2);
        printf ("Форма массива\n");
        for (i = 0; i < FMAS; i++) {
		for (j = 0; j < SMAS; j++)
                	printf ("%.1f ", target1[i][j]);
		printf ("\n");
	};
        printf("\nФорма указателя \n");
    	for (i = 0; i < FMAS; i++) {
        	for (j = 0; j < SMAS; j++)
            		printf ("%.1f ", target2[i][j]);
        	printf ("\n");
    }	
        return 0;

}

void coppy_arr(const int str, const int col, double ar1[str][col], double ar2[str][col])
{
        for(int i = 0; i < str; i++) {
		for(int j = 0; j < col; j++)
			ar2[i][j] = ar1[i][j];
	};
}

void coppy_ptr(const int str, const int col, double (*ar1)[col] , double (*ar2)[col])
{
        for(int i = 0; i < str; i++) 
		for(int j = 0; j < col; j++)
			ar2[i][j] = ar1[i][j];
	
}



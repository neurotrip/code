#include <stdio.h>
#define STR 3
#define COL 5
void s1(const int str, const int col, double ar[str][col]);
void s2(const int str, const int col, double ar[str][col]);
void s3(const int str, const int col, double ar[str][col]);
int main(void)
{
	double mas[STR][COL];

	for(int i = 0, k = 1; i < STR; i++) {
		printf ("Набор %d\n", k++);
		for (int j = 0; j < COL; j++)
			scanf("%lf", &mas[i][j]);
	};
	s1(STR, COL, mas);
	s2(STR, COL, mas);
	s3(STR, COL, mas);
//	for(int i = 0; i < STR; i++) {
//		for(int j = 0; j < COL; j++)
//			printf ("%.1lf ", mas[i][j]);
//		printf ("\n");
//	}

	return 0;
}

void s1(const int str, const int col, double ar[str][col])
{
	int i, j;
	double sr;
	for(i = 0; i < str; i++) {
		for(j = 0; j < col; j++) {
			sr += ar[i][j];
		}
	double average = sr / col;
	printf ("Среднее значение строки %d = %.1lf\n",i+1,  average);
	sr = 0;
	};

}
void s2(const int str, const int col, double ar[str][col])
{
        int i, j;
        double sr;
        for(i = 0; i < str; i++) {
                for(j = 0; j < col; j++) {
                        sr += ar[i][j];
                }
	}
        double average = sr / (str*col);
        printf ("Среднее значение всех чисел =  %.1lf\n",  average);
        

}
void s3(const int str, const int col, double ar[str][col])
{
        int i, j;
        double max = ar[0][0];
        for(i = 0; i < str; i++) {
                for(j = 0; j < col; j++) {
                        if (max < ar[i][j])
			{
				max = ar[i][j];
			}
                }
	}

        printf ("Максимальное число = %.1lf\n", max);
  

}


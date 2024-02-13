#include <stdio.h>
#include <string.h>

int bintoint(char *bs);
void int_to_bin(int n, char *bs);

int main(void) 
{
	char bin_str_1[100];
	char bin_str_2[100];

	unsigned int num_1 = 0;
	unsigned int num_2 = 0;
	int oper_and;
	int oper_or;
	int oper_xor;

	printf("Введите первое число в двоичном виде\n");
	fgets(bin_str_1, 100, stdin);
	if (bin_str_1[strlen(bin_str_1) - 1] == '\n') {
		bin_str_1[strlen(bin_str_1) - 1] = '\0';
	}
	printf("Введите второе число в двоичном виде\n");
	fgets(bin_str_2, 100, stdin);
	if (bin_str_2[strlen(bin_str_2) - 1] == '\n') {
         bin_str_2[strlen(bin_str_2) - 1] = '\0';
    }
	num_1 = bintoint(bin_str_1);
	num_2 = bintoint(bin_str_2);
	oper_and = num_1 & num_2;
	oper_or = num_1 | num_2;
	oper_xor = num_1 ^ num_2;
		
	int_to_bin(~num_1, bin_str_1);
	int_to_bin(~num_2, bin_str_2);

	printf("Операция ~ для первого числа %s\n", bin_str_1);
	printf("Операция ~ для второго числа %s\n", bin_str_2);
	int_to_bin(oper_and, bin_str_1);
	printf("Операция & равна %s\n", bin_str_1);
	int_to_bin(oper_or, bin_str_1);
	printf("Операция | равна %s\n", bin_str_1);
	int_to_bin(oper_xor, bin_str_1);
	printf("Операция ^ равна %s\n", bin_str_1);

	return 0;

}

int bintoint(char *bs) 
{
	unsigned int num;

	for (int i = 0; bs[i] != '\0'; i++) {
		num <<= 1;
		if (bs[i] == '1') {
			num |= 1;
		}
	}

	return num;
}
	
void int_to_bin(int n, char *bs)
{
	int i;
	int size = strlen(bs);
	for (i = size - 1; i >= 0; i--) {
		bs[size - 1 - i] = ((n >> i) & 1) ? '1' : '0';
	}

	bs[size] = '\0';
}

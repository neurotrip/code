#include <stdio.h>
#include <string.h>

void int_to_bin(int n, char *bs);
int count_set_bits(int n);
int main(void)
{
	char bin_str[8 * sizeof(int) + 1];
	int number = 0;
	printf("Введите значение типа int:\n");
	scanf("%d", &number);
	int_to_bin(number, bin_str);
	printf("%s\n", bin_str);
	int count = count_set_bits(number);
	printf("Количество включенных разрядов %d\n", count);

    return 0;

}

void int_to_bin(int n, char *bs)
{
    int i;
    int size = 8 * sizeof(int);
    for (i = size - 1; i >= 0; i--) {
        bs[size - 1 - i] = ((n >> i) & 1) ? '1' : '0';
    }

    bs[size] = '\0';
}

int count_set_bits(int n)
{
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}

	return count;
}


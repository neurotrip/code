#include <stdio.h>
#include <string.h>

void int_to_bin(int n, char *bs);
int position_set_bits(int n, int p);
int main(void)
{
    char bin_str[8 * sizeof(int) + 1];
    int number = 0;
	int position = 0;
	int how_pos = 0;
    printf("Введите значение типа int:\n");
    scanf("%d", &number);
	printf("Введите позицию разряда\n");
	scanf("%d", &position);
    int_to_bin(number, bin_str);
    printf("%s\n", bin_str);
    how_pos = position_set_bits(number, position);

    if (how_pos == 1)
		printf("Разряд в этой позиции включен\n");
	else 
		printf("Разряд в этой позиции выключен\n");
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

int position_set_bits(int n, int p)
{
	if (n & (1 << (p - 1)))
		return 1;
	else 
		return 0;
}


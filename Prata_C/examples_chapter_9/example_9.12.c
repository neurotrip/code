#include <stdio.h>
void mikado(int);
int main(void)
{
	int pooh = 2, bah =5;

	printf ("В функции main() pooh = %d и &pooh = %p\n)", pooh, &pooh);
	printf ("В функции main() bah = %d и &bah = %p\n)", bah, &bah);
	mikado(pooh);

	return 0;
}

void mikado(int bah)
{
	int pooh = 10;

	printf ("В функции mikado() pooh = %d и &pooh = %p\n", pooh, &pooh);
	printf ("В функции mikado() bah = %d и &bah = %p\n", bah, &bah);
}


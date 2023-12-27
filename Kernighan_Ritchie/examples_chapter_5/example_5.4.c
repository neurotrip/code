#include <stdio.h>

#define ALLOCSIZE 3

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp  >= n) {
		allocp += n;
		return allocp -n;
	} else {
		return 0;
	}
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}

int main(void ) {
	char *ptr1, *ptr2;

	ptr1 = alloc(5);
	if (ptr1 != 0) {
		printf ("Выделено: %p\n", ptr1);
	} else {
		printf ("Ошибка выделения памяти. \n");
		
	}
	afree(ptr1);
	ptr2 = alloc(3);
	if (ptr2 != 0) {
		printf ("Выделено: %p\n", ptr2);
	} else {
		printf ("Ошибка выделения памяти.\n");
	}

	afree(ptr1);

	char *ptr3 = alloc(2);

	if (ptr3 != 0) {
		printf ("Выделено: %p\n", ptr3);
	} else {
		printf ("Ошибка выделения памяти.\n");
	}

	return 0;
}


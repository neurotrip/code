#include <stdio.h>

int strindex(char s[], char t[]);

int main() {
    char s[] = "Hello, World!";
    char t[] = "World";

    int result = strindex(s, t);

    if (result != -1) {
        printf("Индекс найден: %d\n", result);
    } else {
        printf("Индекс не найден.\n");
    }

    return 0;
}

int strindex(char s[], char t[]) {
    char *sptr, *tptr, *start;
    for (int i = 0; s[i] != '\0'; i++) {
	    sptr = &s[i];
	    tptr = t;
	    start = sptr;
	    while ( *tptr != '\0' && *sptr == *tptr)
	    {
		    sptr++;
		    tptr++;
	    }
    
        if (*tptr == '\0') {
            return (int)(start - s);
	}
    }
    
    return -1;
}


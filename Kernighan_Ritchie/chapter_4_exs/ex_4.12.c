#include <stdio.h>

void reverse(char s[], int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int recursive_itoa(int n, char s[], int i) {
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        i = recursive_itoa(n / 10, s, i);

    s[i++] = n % 10 + '0';
    return i;
}

void itoa(int n, char s[]) {
    int i = recursive_itoa(n, s, 0);
    s[i] = '\0';

    reverse(s, 0, i - 1);
}

int main() {
    int num = -12345;
    char str[20];

    itoa(num, str);

    printf("Integer: %d\nString: %s\n", num, str);

    return 0;
}


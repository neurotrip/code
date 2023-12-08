#include <stdio.h>
#include <string.h>
#define M_L 1000
void reverse(char s[]);

int main()
{
char str[M_L];
fgets(str, M_L,stdin);
reverse(str);
printf ("Reverse: %s\n", str);

return 0;
}


void reverse(char s[]) {
int length = strlen(s);
for (int i = 0, j = length - 1; i < j; i++, j--) {
char temp = s[i];
s[i] = s[j];
s[j] = temp;
}
}

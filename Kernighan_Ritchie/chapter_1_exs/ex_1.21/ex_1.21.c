#include <stdio.h>


int main()
{
int c;
int space = 0;
while((c = getchar()) != EOF){
if(c == ' ' && space == 0){
++space;
putchar('\t');
}
if(c != ' '){
space = 0;
putchar(c);
}
}
return 0;
}

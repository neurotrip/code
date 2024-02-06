#include <stdio.h>
#define TAB 8

int main()
{
 int c, i, symvol, ntab;
    
 symvol=1;//количество введённых символов до табуляци
 while((c=getchar()) != EOF)
 {
  if(c=='\t')
  {
   //определяем количество пробелов
   //нужных для вставки
   ntab = TAB - (symvol-1);
   for(i=0; i<ntab; i++){
    putchar('|');//тут должен стоять пробел
   symvol=0;
   }
  }
  else if(c=='\n')
  { 
   symvol=0;
   printf("\n");
  }
  else {
   putchar(c);
   symvol++;
            if(symvol==TAB)
                symvol=0;
  }
 }
 return 0;
}

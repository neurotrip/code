#include <stdio.h>
#define MAXLINE 1000

int getline2 ( char string[], int length );
void copy ( char to[], char from[] );

int main ( void ) {
 int len, max;
 char line[ MAXLINE ], longest[ MAXLINE ];
 len = max = 0;
 while ( ( len = getline2 ( line, MAXLINE ) ) > 0 )
  if ( len > max ) {
   max = len;
   copy ( longest, line );
  }
 if ( max > 0 )
  printf ( "Длина самой длинной строки:%d\n%s", max, longest );
 return 0;
}

int getline2 ( char s[], int len ) {
 int c, i, j;
 for ( i = j = 0; ( c = getchar () ) != EOF && c != '\n'; ++i )
  if ( i < len - 1 ) {
   s [ j ] = c;
   ++j;
  }

 if ( c == '\n' ) {
  s [ j ] = c;
  ++j;
  ++i;
 }
 s [ j ] = '\0';
 return i;
}

void copy ( char to[], char from[] ) {
 for ( int i = 0; ( to [ i ] = from [ i ] ) != '\0'; ++i );
}

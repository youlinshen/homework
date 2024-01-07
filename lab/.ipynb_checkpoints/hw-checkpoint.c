#include <stdio.h>
#include <ctype.h>

int main(){
   int a1 = 'A';
   int a2 = ' ';

    if( isspace(a1) )
       printf("a1 = |%c| 是空白字符\n", a1 );
    else
       printf("a1 = |%c| 不是空白字符\n", a1 );
    if( isspace(a2) )
       printf("a2 = |%c| 是空白字符\n", a2 );
    else
       printf("a2 = |%c| 不是空白字符\n", a2 );
    return 0;
}
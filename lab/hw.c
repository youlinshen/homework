#include <stdio.h>
#include <ctype.h>


    int main(){
        int a1 = 'A';
        int a2 = 'f';
        if( isupper(a1) )
           printf("a1 = |%c| 是大寫字母\n", a1 );
        else
           printf("a1 = |%c| 不是大寫字母\n", a1 );
        if( isupper(a2) )
           printf("a2 = |%c| 是大寫字母\n", a2 );
        else
           printf("a2 = |%c| 不是大寫字母\n", a2 );
        return 0;
    }
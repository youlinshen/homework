#include <stdio.h>
#include <string.h>

int main (){
   char a1[16];
   strcpy(a1, "This is a book");
   printf("%s 的長度是 %ld\n", a1, strlen(a1));
   return 0;
}
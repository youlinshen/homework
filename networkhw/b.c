#include <stdio.h>

int main(){
    char ap[10] = {0};
    scanf("%s", ap);
    printf("%s\n", ap);
    printf("%p\n", ap);
    printf("%p\n", &ap[0]);
    printf("%p\n", &ap[1]);
    return 0;
}
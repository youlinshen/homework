#include<stdio.h>

int main(){
    int i, j;
    for ( j = 1; j <= 9; j++){
        for ( i = 1; i <= 9; i++)
            printf("%dx%d=%2d ", i, j, i*j);
        printf("\n");
    }
}
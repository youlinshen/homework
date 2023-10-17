#include<stdio.h>

int main(){
    int i, j;
    for ( j = 1; j <= 9; j+1){
        for ( i = 1; i <= 9; i++)
            printf("%dx%d=%d ", i, j, i*j);
        printf("\n");
    }
}
#include <stdio.h>

int main(){
    int n, temp, i, j;
    scanf("%d", &n);
    int number[n];
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);
    for (j = n; j > 0; j--){
        for ( i = 0; i < j-1; i++)
            if (number[i] > number[i+1]){
                temp = number[i];
                number[i] = number[i+1];
                number[i+1] = temp;
            }
    }
    for ( i = 0; i < n; i++)
        printf("%d ", number[i]);

    for ( i = 0; i < n; i++)
        if (number[i] & 1 == 1)
            printf("%d ", number[i]);
    printf("\n");
    for ( i = 0; i < n; i++)
        if (number[i] & 1 == 0)
            printf("%d ", number[i]);
    return 0;
}

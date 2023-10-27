#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define ARRAYSIZE n+1

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    assert(n >= 2);
    bool prime[ARRAYSIZE];
    for (i = 2; i < ARRAYSIZE; i++)
        prime[i] = true;
    for (i = 2; i < ARRAYSIZE; i++)
        for (j = 2; i*j < ARRAYSIZE; j++)
            prime[i*j] = false;
    for (k = 2; k < ARRAYSIZE; k++)
        if (prime[k] == 1)
            printf("%d ", k);        
    return 0;
}
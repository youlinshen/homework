#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    bool prime[n+1];
    assert(n >= 2);
    for (i = 2; i < n+1; i++)
        prime[i] = true;
    for (i = 2; i < n+1; i++)
        for (j = 2; i*j < n+1; j++)
            prime[i*j] = false;
   
 if (prime[n] == 1)
            printf("1");        
    return 0;
}
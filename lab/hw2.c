#include <stdio.h>

int Look_for(int n, int quantity, int class[n]){
    int i, sum = 0;
    for ( i = 0; i < n; i++){
            sum += class[i];
            if (quantity <= sum){
                printf("%d ", i+1);
                return 0;
            }
        }
}

int main(){
    int n, m, i; 
    scanf("%d", &n);
    int class[n];
    for (i = 0; i < n; i++)
        scanf("%d", &class[i]);
    scanf("%d", &m);
    int look_for[m];
    for ( i = 0; i < m; i++)
        scanf("%d", &look_for[i]);
    for ( i = 0; i < m; i++)
        Look_for(n, look_for[i], class);
    return 0;
}

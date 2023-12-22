#include <stdio.h>

int main(){
    int n, d, i;
    scanf("%d%d", &n, &d);
    int weight[n], max = 0;
    for (i = 0; i < n; i++){
        scanf("%d", weight[i]);
        if (max < weight[i])
            max = weight[i];
    }
    
    
}
#include <stdio.h>

int main(){
    int n;
    int d;
    int i;
    int p = 0;
    int start = 0;
    scanf("%d%d", &n, &d);
    int weight[n], max = 0;
    for (i = 0; i < n; i++){
        scanf("%d", &weight[i]);
        if (max < weight[i])
            max = weight[i];
    }
    while (1){
        int sum = 0;
        for ( i = start; i < n; i++){
            if ((sum + weight[i]) <= max){
                sum += weight[i];
                if (i == n-1)
                    start = n-1;
            }
            else{
                p += 1;
                start = i;
                break;
            }
        }
        if (p+1 > d){
            max += 1;
            p = 0;
            start = 0;
        }
        else if (p+1 == d && start == n-1)
            break;
    }
    printf("%d", max);
    return 0;
}
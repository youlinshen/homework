#include <stdio.h>

int main(){
    int n, m, i; 
    scanf("%d", &n);
    float height[n], weight[n];
    for (i = 0; i < n; i++)
        scanf("%f%f", &height[i], &weight[i]);
    float BMI[n];
    for (i = 0; i < n; i++)
        BMI[i] = weight[i]/(height[i]*height[i]);
    for ( i = 0; i < n; i++)
    {
        if (BMI[i] = )
        {
            /* code */
        }
        
    }
    
    
    return 0;
}

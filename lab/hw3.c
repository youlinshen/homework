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
    printf("Underweight:");
    for ( i = 0; i < n; i++)
        if (BMI[i] < 18.5)
            printf("No.%d ", i+1);
    printf("Normal:");
    for ( i = 0; i < n; i++)
        if (BMI[i] >= 18.5 && BMI[i] < 24)
            printf("No.%d ", i+1);
    printf("Overweight:");
    for ( i = 0; i < n; i++)
        if (BMI[i] >= 24 && BMI[i] < 27)
            printf("No.%d ", i+1);
    printf("Obese:");
    for ( i = 0; i < n; i++)
        if (BMI[i] >= 27)
            printf("No.%d ", i+1);
    return 0;
}

#include <stdio.h>
 
int main(){
    int A[4] = {9, 3, 4, 5}, B[4] = {5, 4, 3, 8};
    int AB[4] = {A[0]*B[0]+A[1]*B[2], 
                 A[0]*B[1]+A[1]*B[3], 
                 A[2]*B[0]+A[3]*B[2], 
                 A[2]*B[1]+A[3]*B[3]}; 
    printf("%d %d %d %d\n", AB[0], AB[1], AB[2], AB[3]);
    return 0;
}

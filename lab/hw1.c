#include <stdio.h>

int main(){
    int n, i, j, k = 0;
    scanf("%d", &n);
    int Identity_matrix[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &Identity_matrix[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Identity_matrix[i][j] != 0 && Identity_matrix[i][j] != 1){
                printf("no");
                return 0;
            }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (j == k)
                continue;
            else if (Identity_matrix[i][j] != 0){
                printf("no");
                return 0;
            }
        }    
        if (Identity_matrix[i][k] == 1)
            k += 1;
        else{
            printf("no");
            return 0;
        }
    }
    printf("yes");   
    return 0;
}

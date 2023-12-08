int main(){
    int n, m, i, j, sum = 0; 
    scanf("%d", &n);
    int class[n];
    for (i = 0; i < n; i++)
        scanf("%d", &class[i]);
    scanf("%d", &m);
    int look_for[m];
    for ( i = 0; i < m; i++)
        scanf("%d", &look_for[i]);
    for ( j = 0; j < m; j++)
        for ( i = 0; i < n; i++){
            sum += class[i];
            if (look_for[j] <= sum)
                printf("%d ", i+1);
        }
    return 0;
}
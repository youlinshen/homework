#include <stdio.h>
#include <string.h>

int main (){
    int n , m, i;
    int n1, n2;
    char s1[10], s2[10];
    scanf("%d %d", &n, &m);
    int win[n];
    for (i = 0; i < n; i++)
        win[i] = 0;
    for (i = 0; i < m; i++){
        scanf("%d %s %d %s", &n1, &s1, &n2, &s2);
        int k1, k2;
        if (strcmp(s1,"Scissors") == 0)
            k1 = 1;
        if (strcmp(s1,"Stone") == 0)
            k1 = 2;
        if (strcmp(s1,"Paper") == 0)
            k1 = 3;
        if (strcmp(s2,"Scissors") == 0)
            k2 = 1;
        if (strcmp(s2,"Stone") == 0)
            k2 = 2;
        if (strcmp(s2,"Paper") == 0)
            k2 = 3;
        if ((k1-k2) == 1)
            win[n1-1] += 1;
        else if ((k1-k2) == -1)
            win[n2-1] += 1;
        else if ((k1-k2) == -2)
            win[n1-1] += 1;
        else if ((k1-k2) == 2)
            win[n2-1] += 1;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", win[i]);
   return 0;
}
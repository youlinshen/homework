    #include <stdio.h>
    #include <string.h>

    int main () {
    char a1[15] = "abcdef";
    char a2[5];
    strncpy(a2, a1, 3);
    printf("%s", a2);
    return 0;
    }
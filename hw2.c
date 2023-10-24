#include<stdio.h>

int main(){
    int chess[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 2, 0, 0},
                       {0, 0, 2, 2, 2, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0}};
    int i = 4, j = 3;s
    switch (chess[i][j]){
    case 0:
    printf("nothing");
        break;
    case 1:
    printf("black");
        break;
    case 2:
    printf("white");
        break;
    }
}
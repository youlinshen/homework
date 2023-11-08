#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define IN_CHESS(x,y) (x >= 0 &&  x <= 7 && y >= 0 && y <= 7)

int CheckNewStepByColor(int chess[8][8], int next[8][8], int color){
    int i, j, x, y, dx, dy;
    for (i = 0; i<= 7; i++)
        for (j = 0; j <= 7; j++)
            next[i][j] = 0;
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++){
            if (chess[i][j] == 0){
                for (dx = -1; dx <= 1; dx++)
                    for (dy = -1; dy <= 1; dy++){
                        x = i + dx, y = j + dy;
                        while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                            x += dx, y += dy;
                            if (chess[x][y] == color && IN_CHESS(x,y))
                                next[i][j] = 1;
                        }
                    }
            }  
        }
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++)
            if(next[i][j] == 1)
                printf("(%d,%d) ", i, j);
    printf("\n");
}

int ChangeColor(int chess[8][8], int color, int i, int j){
    int x, y, dx, dy;
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++){
            x = i + dx, y = j + dy;
            while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                x += dx, y += dy;
                if (chess[x][y] == color && IN_CHESS(x,y)){
                    int p = i, q = j;
                    p += dx, q += dy;
                    while (chess[p][q] == 3-color && IN_CHESS(p,q)){
                        chess[p][q] = color;
                        p += dx, q += dy;
                    }
                }
            }
        }
    chess[i][j] = color;
}

int ChangeNumber(int chess[8][8], int color, int i, int j){
    int x, y, dx, dy, time, total[1] = {0};
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++){
            x = i + dx, y = j + dy, time = 0;
            while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                x += dx, y += dy, time += 1;
                if (chess[x][y] == color && IN_CHESS(x,y)){
                    total[0] += time;
                }
            }
        }
    printf("翻轉%d個棋子\n", total[0]);
}

int PrintBoard(int chess[8][8]){
    for (int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }
}

int main(){
    int chess[8][8] = {{0, 0, 2, 0, 2, 0, 0, 0},
                       {0, 0, 2, 2, 1, 1, 0, 0},
                       {0, 0, 2, 1, 1, 0, 0, 0},
                       {0, 0, 2, 1, 2, 0, 0, 0},
                       {0, 0, 2, 2, 2, 0, 0, 0},
                       {0, 0, 2, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0}};
    int next[8][8];
    int color = 1, i, j;
    PrintBoard(chess);
    CheckNewStepByColor(chess,next,color);
    scanf("%d%d", &i, &j);
    assert(next[i][j] == 1);
    ChangeNumber(chess,color,i,j);
    ChangeColor(chess,color,i,j);
    PrintBoard(chess);
}
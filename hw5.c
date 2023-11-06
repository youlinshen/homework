#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define IN_CHESS(x,y) (x >= 0 &&  x <= 7 && y >= 0 && y <= 7)

int CheckNewStepByColor(int chess[8][8], int next[8][8], int color){
    int x, y, dx, dy;
    int i, j;
    for (i = 0; i<= 7; i++)
        for (j = 0; j <= 7; j++)
            next[i][j] = 0;
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++){
            if (chess[i][j] == 0){
                for (dx = -1; dx <= 1; dx++)
                    for (dy = -1; dy <= 1; dy++){
                        x = i + dx, y = j + dy;
                        if (chess[x][y] == 3-color && IN_CHESS(x,y)){
                            while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                                x += dx;
                                y += dy;
                                if (chess[x][y] == color && IN_CHESS(x,y))
                                next[i][j] = 1;
                            }
                        }
                    }
            }  
        }
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++)
            if(next[i][j] == 1)
                printf("(%d,%d) ", i, j);
}

int main(){
    int chess[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 0, 0, 0, 0},
                       {0, 0, 2, 1, 2, 2, 0, 0},
                       {0, 0, 0, 1, 2, 0, 0, 0},
                       {0, 0, 0, 2, 1, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0}};
    int next[8][8];
    int squeeze[8][8];
    int color;
    scanf("%d", &color);
    assert(color ==1 || color ==2);
    CheckNewStepByColor(chess,next,color);
}

int PlayChess(int chess[8][8], int color, int i, int j, int dx, int dy);
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++){
            x = i + dx, y = j + dy;
            if (chess[x][y] == 3-color && IN_CHESS(x,y)){
                while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                    x += dx;
                    y += dy;
                    if (chess[x][y] == color && IN_CHESS(x,y))
                        ChangeColor(chess[8][8],color,i,j,dx,dy);
                }
            }
        }            

int ChangeColor(int chess[8][8], int color, int i, int j, int dx, int dy){
    i += dx;
    j += dy;
    while (chess[i][j] == color-3 && IN_CHESS(x,y)){
        chess[i][j] = color;
        i += dx;
        j += dy;
    }
}
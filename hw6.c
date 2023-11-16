#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define IN_CHESS(x,y) (x >= 0 &&  x <= 7 && y >= 0 && y <= 7)

int CheckNewStepByColor(int chess[8][8], bool next[8][8], int color){
    int i, j, x, y, dx, dy;
    for (i = 0; i<= 7; i++)
        for (j = 0; j <= 7; j++)
            next[i][j] = false;
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++){
            if (chess[i][j] == 0){
                for (dx = -1; dx <= 1; dx++)
                    for (dy = -1; dy <= 1; dy++){
                        x = i + dx, y = j + dy;
                        while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                            x += dx, y += dy;
                            if (chess[x][y] == color && IN_CHESS(x,y))
                                next[i][j] = true;
                        }
                    }
            }  
        }
    for (i = 0; i <= 7; i++)
        for (j = 0; j <= 7; j++)
            if(next[i][j] == true)
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

int ChangeQuantity(int chess[8][8], int color, int total[1], int i, int j){
    int x, y, dx, dy, time;
    total[0] = 0;
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
}

int computer(int chess[8][8], int color, bool next[8][8], int total[1], bool finish[2]){
    int sum = 0, x, y;
    color = 3 - color;
    CheckNewStepByColor(chess,next,color);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            if (next[i][j] == 1){
                ChangeQuantity(chess,color,total,i,j);
                if (total[0] >= sum){
                    sum = total[0];
                    x = i, y = j;
                }
            }  
        }
    if (sum == 0){
        finish[1] = false;
        return 0;
    }
    ChangeColor(chess,color,x,y);
    printf("白子下(%d,%d)  翻轉%d個棋子\n", x, y, sum);
}

int PrintBoard(int chess[8][8]){
    for (int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }
}

int player(int chess[8][8], int color, bool next[8][8], int total[1], bool finish[2]){
    int i, j, p = 0;
    CheckNewStepByColor(chess,next,color);
    for (int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++)
            if (next[i][j] == true)
                p = 1;
    }
    if (p == 0){
        finish[0] = false;
        return 0;
    }
    scanf("%d%d", &i, &j);
    assert(next[i][j] == 1);
    ChangeQuantity(chess,color,total,i,j);
    ChangeColor(chess,color,i,j);
    printf("黑子下(%d,%d)  翻轉%d個棋子\n", i, j, total[0]);
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
    int total[1], color = 1;
    bool next[8][8], finish[2] = {true, true};
    while (finish[0] == true || finish[1] == true){
        PrintBoard(chess);
        player(chess,color,next,total,finish);
        PrintBoard(chess);
        computer(chess,color,next,total,finish);
    }
}
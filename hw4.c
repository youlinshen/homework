#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define IN_CHESS(x,y) (x >= 0 &&  x <= 7 && y >= 0 && y <= 7)

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
    int x, y, dx, dy;
    int i, j, color;
    for (int p = 0;  p<= 7; p++)
      for (int q = 0; q <= 7; q++)
        next[p][q] = 0;
    scanf("%d", &color);
    assert(color ==1 || color ==2);
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
for (int p = 0; p<= 7; p++)
      for (int q = 0; q <= 7; q++)
        if(next[p][q] == 1)
          printf("(%d,%d) ", p, q);
}
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define IN_CHESS(x,y) (x >= 0 &&  x <= 7 && y >= 0 && y <= 7)
#define IN_CHESS0(i,j,color) ((i >= 0 &&  j <= 7 && i >= 0 && j <= 7) && (color == 1 || color == 2))

int main(){
    int chess[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0, 0, 0, 0},
                     {0, 0, 2, 1, 2, 2, 0, 0},
                     {0, 0, 0, 1, 2, 0, 0, 0},
                     {0, 0, 0, 2, 1, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0}};
    int chess[8][8];
    int x, y, dx, dy;
    int i, j, color;

}
int checkNewStep(int chess[8][8], int next[8][8], int x, int y){

  bool play = false;
  scanf("%d%d%d", &i, &j, &color);
  assert(IN_CHESS0(i,j,color));
  if (chess[i][j] == 0)
    printf("(%d,%d) 空白 ", i, j);
  else if (chess[i][j] == 1){
    printf("(%d,%d)是黑子", i, j);
    return 0;
  }
  else if (chess[i][j] == 2){
    printf("(%d,%d)是白子", i, j);
    return 0;
  }
  for (dx = -1; dx <= 1; dx++)
    for (dy = -1; dy <= 1; dy++){
        x = i + dx, y = j + dy;
        if (chess[x][y] == 0 && IN_CHESS(x,y))
            play = play | 0;
        else if (chess[x][y] == color && IN_CHESS(x,y))
            play = play | 0;
        else if (chess[x][y] == 3-color && IN_CHESS(x,y)){
            while (chess[x][y] == 3-color && IN_CHESS(x,y)){
                x += dx;
                y += dy;
            if (chess[x][y] == color && IN_CHESS(x,y))
                play = true;
            }
        }
    }
  if (play == true){
    if (color == 1)
      printf("可以下黑子");
    else
      printf("可以下白子");
  }
  else
    printf("不能下子");
}
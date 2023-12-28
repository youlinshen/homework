#include <stdio.h>

#define length 501

int main(){
    char calculation[length];
    int temp = 0, sum = 0;
    fgets(calculation, length, stdin);
    for(int i = 0; i < 501; i++){
        switch(calculation[i]){
        case '<':
            temp += 10;
            break;
        case '/':
            temp += 1;
            break;
        case '+':
            printf("%d + ", temp);
            sum += temp;
            temp = 0;
            break;
        case '\0':
            sum += temp;
            printf("%d = %d", temp, sum);
            return 0;
        default:
            break;
        }
    }
}

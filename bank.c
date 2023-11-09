#include <stdio.h>

int bank(int OriginalMoney[1], int mode){
    int change, number;
    char country;
    switch (mode){
    case 1:
        scanf("%d", &change);
        if (change <= OriginalMoney[0] && change <= 10000)
            OriginalMoney[0] -= change;
        else{
            printf("Error\n");
            return 0;
        }
        break;
    case 2:
        scanf("%d", &change);
        OriginalMoney[0] += change;
        break;
    case 3:
        scanf("%d %c", &change, &country);
        number = country;
        if (change <= OriginalMoney[0]){
            switch (number){
            case 85:
                printf("America exchange = %.f\n", change/31.96);
                break;
            case 74:
                printf("Japan exchange = %.f\n", change/0.2066);
                break;
            case 69:
                printf("Europe exchange = %.f\n", change/33.42);
                break;
            }
            OriginalMoney[0] -= change; 
        }
        else{
            printf("Error\n");
            return 0;
        }
        break;
    }
    printf("Balance = %d\n", OriginalMoney[0]);
    return 0;
}

int main(){
    int OriginalMoney[1], mode;
    scanf("%d", &OriginalMoney[0]);
    while (1){
        scanf("%d", &mode);
        if (mode != -1)
            bank(OriginalMoney,mode);
        else
            return 0;
    }
}
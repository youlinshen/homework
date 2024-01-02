#include <stdio.h>
#include <stdlib.h>

typedef struct Locdata{
    char name[6];
    int x;
    int y;
    struct Locdata *next;
} data;

int main(){
    int local[13][2], i = 0;
    data *head;
    data *ptr;
    head = (data*)malloc(sizeof(data));
    ptr = head;
    for(int i = 0; i < 13; i++){
        scanf("%s %d %d", &(ptr->name), &(ptr->x), &(ptr->y));
        printf("\n");
        ptr->next = (data*)malloc(sizeof(data));
        ptr = ptr->next;
        ptr->next = NULL;
    }
    for(; head != NULL; head = head->next){
        printf("%s %d %d\n", head->name, head->x, head->y);
        local[i][0] = head->x;
        local[i][1] = head->y;
        i++;
    }
    for(i = 0; i<13; i++)
        printf("%d , %d\n", local[i][0], local[i][1]);
    return 0;
}
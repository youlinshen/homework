#include <stdio.h>
#include <stdlib.h>

typedef struct Locdata{
    char name[6];
    int x;
    int y;
    struct Locdata *next;
} data;

int main(){
    data *head;
    data *ptr;
    head = (data*)malloc(sizeof(data));
    ptr = head;
    for(int i = 0; i < 13; i++){
        fgets(ptr->name, 6, stdin);
        scanf("%d %d", &(ptr->x), &(ptr->y));
        printf("\n");
        ptr->next = (data*)malloc(sizeof(data));
        ptr = ptr->next;
        ptr->next = NULL;
    }
    for(; head != NULL; head = head->next)
        printf("%s %d %d\n", head->name, head->x, head->y);
    return 0;
}
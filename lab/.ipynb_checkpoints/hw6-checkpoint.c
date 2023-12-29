#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

int insert(node **ptr, int data){
    //node *ptr = head;
    if(*ptr != NULL)
        for(; *ptr != NULL; *ptr = *ptr->next)
            if(ptr->next == NULL){
                ptr->next = (node*)malloc(sizeof(node));
                ptr = ptr->next;
                ptr->data = data;
                ptr->next = NULL;
                return 0;
            }
    else if(ptr == NULL){
        head = (node*)malloc(sizeof(node));
        head->data = data;
        head->next = NULL;
        return 0;
    }
}

int print_list(node *head){
    for(; head != NULL; head = head->next)
        printf("%d ", head->data);
}

int main(){
    int data;
    node *head = NULL;
    //node *list1 = (node*)malloc(sizeof(node));
    //assert(list1 != NULL);
    printf("%d\n", scanf("%d", &data));
    printf("%p\n", head);
    insert(&head, data);
    print_list(head);
}
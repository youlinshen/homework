#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;
int insert(node *list1){
    
}

int print_list(node *list1){
    for(; list1 != NULL; list1 = list1->next)
        printf("%d ", list1->data);
}

int main(){
    node *list1 = (node*)malloc(sizeof(node));
    assert(list1 != NULL);
    list1->data = 1;
    node *list2 = (node*)malloc(sizeof(node));
    assert(list2 != NULL);
    list2->data = 2;
    list1->next = list2;
    list2->next = NULL;
    print_list(list1);
}
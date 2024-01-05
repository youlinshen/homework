#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int data;
    struct Node* next;
} node;
 
int freeAll(node *head){
    node *temp;
    node *current;
    current = head;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
}
 
int insert(node **head, int value){
    node *new = (node*)malloc(sizeof(node));
    new->data = value;
    new->next = NULL;
    if(*head != NULL){
        node *last = *head;
        while(last->next != NULL)
            last = last->next;
        last->next = new;
    }
    else
        *head = new;
    return 0;
}
 
int delete(node **head){
    node *last = *head;
    node *temp = NULL;
    if(last == NULL)
        return 0;
    else if(last->next != NULL){
        while(last->next != NULL){
            temp = last;
            last = last->next;
        }
        free(last);
        temp->next = NULL;
    }
    else{
        free(last);
        *head = NULL;
    }
    return 0;
}
 
int print_list(node *head){
    if(head == NULL)
        return 0;
    for(; head != NULL; head = head->next)
        printf("%d ", head->data);
    printf("\n");
    return 0;
}
 
int main(){
    int value;
    int mode;
    node *head = NULL;
    while(1){
        if( 1 != scanf("%d", &mode)){
            mode = 4;
            setbuf(stdin, NULL);
        }
        switch(mode){
            case 0:
                freeAll(head);
                return 0;
            case 1:
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                print_list(head);
                break;
            default:
                break;
        }
    }
}

#include "graph.h"

adj *priority_head[Max];
adj *priority_tail[Max];

int initQ(){
    for(int i = 0; i < Max; i++){
        priority_head[i] = 0;
        priority_tail[i] = 0;
    }
    return 0;
}

int insertQ(int priority, adj *newNode){
    if (priority < 0 || priority >= Max)
        return -1;
    newNode->next = 0;

    if(priority_head[priority] == 0){
        priority_head[priority] = newNode;
        priority_tail[priority] = newNode;
    }
    else{
        priority_tail[priority]->next = newNode;
        priority_tail[priority] = newNode;
    }
    return 0;
}


node *deleteQ(){
    node *data = 0;
    for(int i = 0; i < Max; i++){
        if(priority_head[i] != 0){
            if(priority_head[i]->next != 0){
                data = priority_head[i]->data;
                priority_head[i] = priority_head[i]->next;
            }
            else{
                data = priority_head[i]->data;
                priority_head[i] = 0;
                priority_tail[i] = 0;
            }
            break;
        }
    }
    return data;
}

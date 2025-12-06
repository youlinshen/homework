#include "graph.h"

adj *pri_head[Max];
adj *pri_tail[Max];

int initQ(){
    for(int i = 0; i < Max; i++){
        pri_head[i] = 0;
        pri_tail[i] = 0;
    }
    return 0;
}

int insertQ(int priority, adj *node){
    node->next = 0;
    if(pri_head[priority] == 0){
        pri_head[priority] = node;
        pri_tail[priority] = node;
    }
    else{
        pri_tail[priority]->next = node;
        pri_tail[priority] = node;
    }
    return 0;
}


node *deleteQ(){
    node *data = 0;
    for(int i = 0; i < Max; i++){
        if(pri_head[i] != 0){
            if(pri_head[i]->next != 0){
            data = pri_head[i]->data;
            pri_head[i] = pri_head[i]->next;
            }
            else{
                data = pri_head[i]->data;
                pri_head[i] = 0;
                pri_tail[i] = 0;
            }
            break;
        }
    }
    return data;
}
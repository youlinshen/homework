#ifndef __GRAPH_H__
#define __GRAPH_H__

#define Max 128

struct Node{
    int priority;
    void * data;
};typedef struct Node node;


struct Adjacent_list{
    node *data;
    struct Adjacent_list *next;
};typedef struct Adjacent_list adj;

//extern adj *priority_head[Max];
//extern adj *priority_tail[Max];

int insertQ(int priority, adj * NewNode);
node *deleteQ();
int initQ();

#endif

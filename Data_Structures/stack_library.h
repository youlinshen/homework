#ifndef __STACK_H__
#define __STACK_H__

#define STACK_OK        0
#define STACK_FULL      -1
#define STACK_EMPTY     -2
#define STACK_FAIL      -3

typedef struct stack{
    void **elements;
    unsigned size;
    int sp;
} stack_t;

int init(stack_t *, int size);
int isFULL(stack_t *);
int isEmpty(stack_t *);
int push(stack_t *, void *);
int pop(stack_t *, void **retVodeAddress);
int isExist(stack_t *, int x);

#endif
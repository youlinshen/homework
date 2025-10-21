#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_OK        0
#define STACK_FULL      -1
#define STACK_EMPTY     -2
#define STACK_FAIL      -3

typedef struct stack{
    int *element;
    unsigned size;
    int sp;
} stack_t;

int init(stack_t *, int size);
int isFULL(stack_t *);
int isEmpty(stack_t *);
int push(stack_t *, int x);
int pop(stack_t *, int *x);
int isExist(stack_t *, int x);

int init(stack_t *stackPtr, int size){
    if (size > 0){
        stackPtr->element = (int *)malloc(size*sizeof(int));
        if (stackPtr->element == NULL) return STACK_FAIL;
        memset(stackPtr->element,-1,size*sizeof(int));
        stackPtr->sp = -1;
        stackPtr->size = size;
        return STACK_OK;
    }
    return STACK_FAIL;
}

int isFULL(stack_t *stackPtr){
    return (stackPtr->sp == stackPtr->size-1);
}

int isEmpty(stack_t *stackPtr){
    return (stackPtr->sp == -1);
}

int push(stack_t *stackPtr, int x){
    if(!isFULL(stackPtr)){
        stackPtr->sp++;
        *(stackPtr->element + stackPtr->sp) = x;
        return STACK_OK;
    }
    return STACK_FULL;
}

int pop(stack_t *stackPtr, int *x){
    if(!isEmpty(stackPtr)){
        x = stackPtr->element[stackPtr->sp];
        stackPtr->sp--;
        return STACK_OK;
    }
    return STACK_EMPTY;
}

int isExst(stack_t *stackPtr, int x){
    for(int i = 0; i <= stackPtr->sp; i++){
        if(stackPtr->element[i] == x)
            return 1;
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int init(stack_t *stackPtr, int size){
    if (size > 0){
        stackPtr->elements = (void **)malloc(size*sizeof(void *));
        if (stackPtr->elements == NULL) return STACK_FAIL;
        memset(stackPtr->elements, 0, size*sizeof(void *));
        stackPtr->sp = -1;
        stackPtr->size = size;
        return STACK_OK;
    }
    return STACK_FAIL;
}

int isFULL(stack_t *stackPtr){
    return (stackPtr->sp == (int)(stackPtr->size)-1);
}

int isEmpty(stack_t *stackPtr){
    return (stackPtr->sp == -1);
}

int push(stack_t *stackPtr, void *node){
    if(!isFULL(stackPtr)){
        stackPtr->sp++;
        *(stackPtr->elements + stackPtr->sp) = node;
        return STACK_OK;
    }
    return STACK_FULL;
}

int pop(stack_t *stackPtr, void **retNodeAddress){
    if(!isEmpty(stackPtr)){
        *retNodeAddress = stackPtr->elements[stackPtr->sp];
        stackPtr->sp--;
        return STACK_OK;
    }
    return STACK_EMPTY;
}

int isExist(stack_t *stackPtr, int x){
    for(int i = 0; i <= stackPtr->sp; i++){
        if(stackPtr->elements[i] == x)
            return 1;
    }
    return 0;
}


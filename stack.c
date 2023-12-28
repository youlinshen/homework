#include "stack.h"

/*static int isEmpty(stack_t *stackPtr) {
    if (stackPtr->top==-1) return 1;
    return 0;
}

static int isFull(stack_t *stackPtr) {

}*/

void push(stack_t *stackPtr, axis_t element) {
    stackPtr->top++;
    stackPtr->elements[stackPtr->top] = element;
    //memcpy(&stack.elements[stack.stack_pointer], &element, sizeof(element));
}

axis_t pop(stack_t *stackPtr){
    axis_t temp={-1,-1};
    if (isEmpty(stackPtr)) return temp;
    temp = stackPtr->elements[stackPtr->top];
    stackPtr->top--;
    return temp;
}

int isEmpty(stack_t *stackPtr) {
    if (stackPtr->top==-1) return 1;
    return 0;
}

int isFull(stack_t *stackPtr) {

}

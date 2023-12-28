#ifndef __stack_h__
#define __stack_h__

#define M_SIZE 10

#define EQU(p,q) (p.x==q.x && p.y==q.y)


typedef struct axis {
    int x;
    int y;
} axis_t;

typedef struct  {
    axis_t elements[M_SIZE*M_SIZE];
    int top;
} stack_t;

void push(stack_t *stack, axis_t axis);
axis_t pop(stack_t *stack);
int isEmpty(stack_t *stack);

#endif

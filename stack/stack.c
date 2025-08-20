/*
 * Implementation of the ADT Stack
 */

#include<stdlib.h>
#include<stdio.h>

#include "stack.h"


enum {
    STACK_CAPACITY = 4096,
};


struct Stack {
   int items[STACK_CAPACITY];
   size_t sz;
};


Stack *stack_new() {
    Stack *stack = malloc(sizeof(Stack));
    stack->sz = 0;
    return stack;
}


void stack_delete(Stack *s) {
    free(s);
}


_Bool stack_empty(Stack *s) {
    return s->sz == 0;
}


_Bool stack_push(Stack *s, int item) {
    if (s->sz == STACK_CAPACITY) {
        return 0;
    }
    s->items[s->sz++] = item;
    return 1;
}


_Bool stack_pop(Stack *s, int *popped) {
    if (stack_empty(s)) {
        return 0;
    }

    *popped = s->items[--s->sz];
    return 1;
}

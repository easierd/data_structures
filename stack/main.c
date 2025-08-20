#include <assert.h>
#include <stdio.h>

#include "stack.h"


int main(void) {
    int item;
    Stack *s = stack_new();
    assert(stack_empty(s));

    assert(!stack_pop(s, &item));

    assert(stack_push(s, 10));
    assert(!stack_empty(s));

    assert(stack_pop(s, &item));

    assert(stack_empty(s));

    assert(item == 10);

    stack_delete(s);
    printf("All test passed\n");

}

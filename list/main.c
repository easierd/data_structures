#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "list.h"


int main(void) {
    List *l = list_new();
    assert(list_empty(l));
    int a = 324;
    l = list_prepend(&l, &a);
    assert(!list_empty(l));

    List *la = list_search(l, &a);
    void *item;
    assert(list_get(la, &item) != NULL);
    int value = *((int*)item);
    assert(value == a);

    list_delete(l);
}

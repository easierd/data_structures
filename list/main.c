#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "list.h"


int main(void) {
    List *l = list_new();
    assert(list_empty(l));

    int a = 324;
    list_prepend(&l, &a);
    list_prepend(&l, NULL);
    assert(!list_empty(l));

    List *la = list_search(l, &a);
    assert(la != NULL);

    void *item;
    list_get(la, &item);
    int value = *((int*)item);
    assert(value == a);

    list_delete(l);
}

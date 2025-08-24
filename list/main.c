#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>
#include "list.h"


int main(void) {
    List *l = list_new();
    assert(list_empty(l));

    char *a = calloc(10, 1);
    list_insert(&l, a);
    list_insert(&l, NULL);
    assert(!list_empty(l));

    List *la = list_find(l, a);
    assert(la != NULL);

    void *item;
    list_get(la, &item);
    char *value = ((char*)item);
    assert(strcmp(value, a) == 0);

    list_delete(l, free);
}

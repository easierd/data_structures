#include <stdio.h>
#include "list.h"


int main(void) {
    List *l = list_new();
    int a = 324;
    l = list_prepend(&l, &a);

    List *la = list_search(l, &a);
    if (la) {
        printf("Found something: \n");
    }

    list_delete(l);
}

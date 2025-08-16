#include "list.h"


int main(void) {
    List *l = list_new();
    int a = 324;
    l = list_prepend(&l, &a);
    list_delete(l);
}

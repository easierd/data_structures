#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bin_tree.h"


#define assert_fail(expr) assert(!(expr))


char *mallocify(const char str[], size_t n) {
    char *c = malloc(n + 1);
    if (c == NULL) {
        return NULL;
    }
    strncpy(c, str, n + 1);
    return c;
}


int main(void) {
    char *c = mallocify("hello", 5);
    char *c1 = mallocify("camel", 5);
    char *c2 = mallocify("hotel_room_service", 19);

    Tree *t = tree_new(c);
    Tree *t1 = tree_new(c1);
    Tree *t2 = tree_new(c2);

    assert(tree_insert_left(t, t1));
    assert(tree_insert_right(t1, t2));
    assert_fail(tree_insert_right(t, t1));
    assert_fail(tree_insert_left(t1, t2));

    Tree *l = tree_remove_left(t);
    assert(l != NULL);
    Tree *r = tree_remove_right(t);
    assert(r == NULL);

    assert(tree_insert_left(l, t));

    assert(strcmp(c1, tree_read(l)) == 0);
    assert(strcmp(c, tree_read(tree_left(l))) == 0);
    assert(strcmp(c2, tree_read(tree_right(l))) == 0);

    tree_delete(l, free);
}

#include<stdlib.h>
#include<stdio.h>

#include "bst.h"


int int_cmp(int *a, int *b) {
    return *b - *a;
}

void print_int (int *a) {
    printf(" %d ", *a);
}


int main(void) {
    int a = 10;
    int b = 30;
    int c = -330;
    int d = 0;

    BSTree *bst = bs_tree_new((int (*)(void *, void*))int_cmp);

    bs_tree_insert(bst, &a);
    bs_tree_insert(bst, &b);
    bs_tree_insert(bst, &c);
    bs_tree_insert(bst, &d);

    bs_tree_inorder_walk(bst,(void (*)(void *))print_int);
    putchar('\n');

    bs_tree_delete(bst, NULL);
}

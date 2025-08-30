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

    BSTreeNode *n1 = bs_tree_node_new(&a, NULL);
    BSTreeNode *n2 = bs_tree_node_new(&b, NULL);
    BSTreeNode *n3 = bs_tree_node_new(&c, NULL);
    BSTreeNode *n4 = bs_tree_node_new(&d, NULL);

    BSTree *bst = bs_tree_new((int (*)(void *, void*))int_cmp);

    bs_tree_insert(bst, n1);
    bs_tree_insert(bst, n2);
    bs_tree_insert(bst, n3);
    bs_tree_insert(bst, n4);


    bs_tree_remove(bst, n3);
    bs_tree_remove(bst, n2);


    bs_tree_node_inorder_walk(bs_tree_root(bst),(void (*)(void *))print_int);
    putchar('\n');

    bs_tree_delete(bst);
}

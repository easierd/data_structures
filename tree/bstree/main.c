#include<stdlib.h>
#include<stdio.h>

#include<time.h>

#include "bst.h"


int int_cmp(int *a, int *b) {
    return *b - *a;
}

void print_int (int *a) {
    printf(" %d ", *a);
}


long long timediff(struct timespec* end, struct timespec* start) {
    return (end->tv_sec - start->tv_sec) * 1000000000LL + 
        (end->tv_nsec - start->tv_nsec);
}


void test_asymptotic_insert(long n) {
    struct timespec start;
    struct timespec end;

    BSTree *bst = bs_tree_new((int (*)(void *, void*))int_cmp);

    BSTreeNode **nodes = malloc(sizeof(BSTreeNode*) * n);
    for (long i = 0; i < n; i++) {
        int *j = calloc(1, sizeof(int));
        nodes[i] = bs_tree_node_new(j, free);
    }

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (long i = 0; i < n; i++) {
        bs_tree_insert(bst, nodes[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Elapsed: %lld\n", timediff(&end, &start));

    bs_tree_delete(bst);
    bs_tree_node_delete(nodes[0]);
    free(nodes);
}


int main(void) {
    test_asymptotic_insert(1000000);
}

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
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


typedef union {
    char op;
    double val;
} expr;


double tree_eval(Tree *t) {
    expr *e = (expr*) tree_read(t);
    if (e->op == 0) {
        return e->val;
    }

    double left_val = tree_eval(tree_left(t));
    double right_val = tree_eval(tree_right(t));

    switch(e->op) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            return left_val / right_val;
        default:
            return 0.0;
    }
}


bool eval() {
    double a = 10;
    double b = 20;
    double c = 30;
    double d = 30;

    double expected = a / b + c * d;
    printf("expected = %f\n", expected);

    expr root = {'+'};


    expr left = {'/'};

    expr leftleft;
    leftleft.val = a;

    expr leftright;
    leftright.val = b;


    expr right = {'*'};

    expr rightleft;
    rightleft.val = c;

    expr rightright;
    rightright.val = d;


    Tree *root_tree = tree_new(&root);

    Tree *left_tree = tree_new(&left);
    Tree *left_left_tree = tree_new(&leftleft);
    Tree *left_right_tree = tree_new(&leftright);

    Tree *right_tree = tree_new(&right);
    Tree *right_left_tree = tree_new(&rightleft);
    Tree *right_right_tree = tree_new(&rightright);


    tree_insert_left(right_tree, right_left_tree);
    tree_insert_right(right_tree, right_right_tree);

    tree_insert_left(left_tree, left_left_tree);
    tree_insert_right(left_tree, left_right_tree);

    tree_insert_right(root_tree, right_tree); 
    tree_insert_left(root_tree, left_tree); 

    double res = tree_eval(root_tree);
    tree_delete(root_tree, NULL);

    printf("res = %f\n", res);
    return res == expected;

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

    assert(eval());

}

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "bin_tree.h"


struct Tree {
    struct Tree *parent;
    struct Tree *left;
    struct Tree *right;
    void *item;
};


Tree *tree_new(void *item) {
   Tree *root = malloc(sizeof(Tree));
   if (root == NULL) {
        return NULL;
   }
   root->parent = NULL;
   root->left = NULL;
   root->right = NULL;
   root->item = item;

   return root;
}


Tree *tree_left(Tree *t) {
    if (t == NULL) {
        return NULL;
    }

    return t->left;
}


Tree *tree_right(Tree *t) {
    if (t == NULL) {
        return NULL;
    }

    return t->right;
}


bool tree_insert_left(Tree *parent, Tree *child) {
    if (parent == NULL || child->parent != NULL || parent->left != NULL) {
        return false;
    }

    parent->left = child;
    child->parent = parent;
    return true;
}


bool tree_insert_right(Tree *parent, Tree *child) {
    if (parent == NULL || child->parent != NULL || parent->right != NULL) {
        return false;
    }

    parent->right = child;
    child->parent = parent;
    return true;
}


Tree *tree_remove_left(Tree *t) {
    if (t == NULL) {
        return NULL;
    }

    Tree *removed = NULL;
    if (t->left != NULL) {
        removed = t->left;
        removed->parent = NULL;
        t->left = NULL;
    }

    return removed;
}


Tree *tree_remove_right(Tree *t) {
    if (t == NULL) {
        return NULL;
    }

    Tree *removed = NULL;
    if (t->right != NULL) {
        removed = t->right;
        removed->parent = NULL;
        t->right = NULL;
    }

    return removed;
}


void *tree_read(Tree *t) {
    if (t == NULL) {
        return NULL;
    }
    return t->item;
}


void tree_delete(Tree *t, void free_callback(void*)) {
    if (t != NULL) {

        tree_delete(t->left, free_callback);
        tree_delete(t->right, free_callback);

        if (free_callback != NULL) {
            free_callback(t->item);
        }

        free(t);
    }
}


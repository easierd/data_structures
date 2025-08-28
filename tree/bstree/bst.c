#include<stdlib.h>

#include "bst.h"

typedef struct BSTreeNode {
    void *item;
    struct BSTreeNode *parent;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
} BSTreeNode;


BSTreeNode *bs_tree_node_new(void *item) {
    BSTreeNode *node = malloc(sizeof(BSTreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->item = item;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void bs_tree_node_inorder_walk(BSTreeNode *node, void (*procedure)(void *)) {
    if (node != NULL) {
        bs_tree_node_inorder_walk(node->left, procedure);
        procedure(node->item);
        bs_tree_node_inorder_walk(node->right, procedure);
    }
}


void bs_tree_node_delete(BSTreeNode *node, void (*free_callback)(void *)) {
    if (node != NULL) {

        bs_tree_node_delete(node->left, free_callback);
        bs_tree_node_delete(node->right, free_callback);

        if (free_callback != NULL) {
            free_callback(node->item);
        }

        free(node);
    }
}



struct BSTree {
    BSTreeNode *root;
    int (*compare)(void *, void*);
};


BSTree *bs_tree_new(int (*compare)(void *, void*)) {
    BSTree *tree = malloc(sizeof(BSTree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;
    tree->compare = compare;

    return tree;
}


void bs_tree_insert(BSTree *tree, void *item) {
    BSTreeNode *node = bs_tree_node_new(item);
    BSTreeNode *cur = tree->root;
    BSTreeNode *cur_parent = NULL;
    while (cur) {
        cur_parent = cur;

        // item < cur->item
        if (tree->compare(item, cur->item) > 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (cur_parent == NULL) {
        tree->root = node;
    } else if (tree->compare(item, cur_parent->item) > 0) {
       cur_parent->left = node;
    } else {
        cur_parent->right = node;
    }
}


void bs_tree_inorder_walk(BSTree *tree, void (*procedure)(void *)) {
    bs_tree_node_inorder_walk(tree->root, procedure);
}


void bs_tree_delete(BSTree *bst, void (*free_callback)(void*)) {
    bs_tree_node_delete(bst->root, free_callback);
    free(bst);
}  

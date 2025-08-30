#include<stdlib.h>

#include "bst.h"

struct BSTreeNode {
    void *item;
    struct BSTreeNode *parent;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    
    void (*free_callback)(void*);
};


struct BSTree {
    BSTreeNode *root;
    int (*compare)(void *, void*);
};


BSTreeNode *bs_tree_node_new(void *item, void (*free_callback)(void*)) {
    BSTreeNode *node = malloc(sizeof(BSTreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->item = item;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    node->free_callback = free_callback;

    return node;
}


BSTreeNode *bs_tree_node_min(BSTreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}


BSTreeNode *bs_tree_node_max(BSTreeNode *node) {
    while (node->right != NULL) {
        node = node->right;
    }

    return node;
}


BSTreeNode *bs_tree_node_successor(BSTreeNode *node) {
    if (node->right != NULL) {
        return bs_tree_node_min(node->right);
    } 
    BSTreeNode *parent = node->parent;
    while (parent != NULL && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}


BSTreeNode *bs_tree_node_predecessor(BSTreeNode *node) {
    if (node->left != NULL) {
        return bs_tree_node_max(node->left);
    }
    BSTreeNode *parent = node->parent;
    while (parent != NULL && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}


void bs_tree_node_inorder_walk(BSTreeNode *node, void (*procedure)(void *)) {
    if (node != NULL) {
        bs_tree_node_inorder_walk(node->left, procedure);
        procedure(node->item);
        bs_tree_node_inorder_walk(node->right, procedure);
    }
}


void *bs_tree_node_get(const BSTreeNode *node) {
    return node->item;
}


void bs_tree_node_delete(BSTreeNode *node) {
    if (node != NULL) {

        bs_tree_node_delete(node->left);
        bs_tree_node_delete(node->right);

        if (node->free_callback != NULL) {
            node->free_callback(node->item);
        }

        free(node);
    }
}


BSTree *bs_tree_new(int (*compare)(void *, void*)) {
    BSTree *tree = malloc(sizeof(BSTree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;
    tree->compare = compare;

    return tree;
}


void bs_tree_insert(BSTree *tree, BSTreeNode* node) {
    BSTreeNode *cur = tree->root;
    BSTreeNode *cur_parent = NULL;
    while (cur) {
        cur_parent = cur;
        if (tree->compare(node->item, cur->item) > 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (cur_parent == NULL) {
        tree->root = node;
    } else if (tree->compare(node->item, cur_parent->item) > 0) {
       cur_parent->left = node;
    } else {
        cur_parent->right = node;
    }
    node->parent = cur_parent;
}


/*
 * replace node n as a child of n->parent with m
 */
static void transplant(BSTree *tree, BSTreeNode *n, BSTreeNode *m) {
    if (n->parent == NULL) {
        tree->root = m;
    } else if (n == n->parent->left) {
        n->parent->left = m;
    } else {
        n->parent->right = m;
    }

    if (m != NULL) {
        m->parent = n->parent;
    }
}


void bs_tree_remove(BSTree *tree, BSTreeNode* node) {
    if (node->left == NULL) {
        transplant(tree, node, node->right);
    } else if (node->right == NULL) {
        transplant(tree, node, node->left);
    } else {
        BSTreeNode *min = bs_tree_node_min(node->right);
        if (min != node->right) {
            transplant(tree, min, min->right);
            min->right = node->right;
            node->right->parent = min;
        }
        transplant(tree, node, min);
        min->left = node->left;
        node->left->parent = min;
    }

    node->left = NULL;
    node->right = NULL;
}


BSTreeNode *bs_tree_root(const BSTree *tree) {
    return tree->root;
}


void bs_tree_delete(BSTree *bst) {
    free(bst);
}  

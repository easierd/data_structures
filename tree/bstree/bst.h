/*
 * Generic Binary Search Tree interface
 */

#pragma once

typedef struct BSTreeNode BSTreeNode;

BSTreeNode *bs_tree_node_new(void *, void (*free_callback)(void *));

void bs_tree_node_delete(BSTreeNode *);


typedef struct BSTree BSTree;


/*
 * Create a new Binary Search Tree.
 *
 * Every BSTree created with this function must be 
 * deleted with a call to bs_tree_delete.
 */
BSTree *bs_tree_new(int (*compare)(void*, void*));


void bs_tree_insert(BSTree*, BSTreeNode*);


BSTreeNode *bs_tree_successor(BSTree *, BSTreeNode*);


BSTreeNode *bs_tree_remove(BSTree*, BSTreeNode*);


void bs_tree_inorder_walk(BSTree *, void (*procedure)(void *));


void bs_tree_delete(BSTree*);

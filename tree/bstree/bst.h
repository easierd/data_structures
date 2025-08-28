/*
 * Generic Binary Search Tree interface
 */

#pragma once

typedef struct BSTree BSTree;


/*
 * Create a new Binary Search Tree.
 *
 * Every BSTree created with this function must be 
 * deleted with a call to bs_tree_delete.
 */
BSTree *bs_tree_new(int (*compare)(void*, void*));


void bs_tree_insert(BSTree *, void *);


void bs_tree_inorder_walk(BSTree *, void (*procedure)(void *));


void bs_tree_delete(BSTree *, void (*free_callback)(void*));

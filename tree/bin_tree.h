/* 
 * Binary Tree interface
 */


#pragma once

#include<stdbool.h>


typedef struct Tree Tree;


/*
 * Create a new isolated Tree with the given item.
 *
 * A Tree object created with this function must be
 * deleted with a call to tree_delete
 */
Tree *tree_new(void*);


/*
 * Return the left child of the given Tree.
 * If the child is not present return NULL
 */
Tree *tree_left(const Tree *);


/*
 * Return the right child of the given Tree.
 * If the child is not present return NULL
 */
Tree *tree_right(const Tree *);


/*
 * Insert lc as the left child of p.
 * An insert is allowed if p has no left child and
 * lc has no parent.
 *
 * Return true if the insert is successful,
 * false otherwise
 */
bool tree_insert_left(Tree *p, Tree *lc);



/*
 * Insert rc as the right child of p.
 * An insert is allowed if p has no right child and
 * rc has no parent.
 *
 * Return true if the insert is successful, 
 * false otherwise
 */
bool tree_insert_right(Tree *p, Tree *rc);



/*
 * Remove the left child from the given Tree.
 *
 * Return the child if present, NULL otherwise
 */
Tree *tree_remove_left(Tree*);


/*
 * Remove the right child from the given Tree.
 *
 * Return the child Tree if present, NULL otherwise
 */
Tree *tree_remove_right(Tree*);



/*
 * Return the item in the root of the given tree.
 * If the argument is NULL, return NULL.
 */
void *tree_read(const Tree*);


/*
 * Delete the entire Tree.
 * If free_callback is not NULL, it's used to free the item of each node.
 *
 * A Tree object deleted with this function must have been created
 * with a call to tree_new
 */
void tree_delete(Tree *t, void (*free_callback)(void*));

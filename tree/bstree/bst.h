/*
 * Generic Binary Search Tree interface
 */

#pragma once

/* 
 * BSTreeNode represents the physical tree data structure.
 * Every operation provided in this interface, assumes that
 * the binary-search-tree property holds.
 */
typedef struct BSTreeNode BSTreeNode;

/*
 * Creates a new tree with the given item.
 * Each Node created with this function must be deleted with
 * a call to bs_tree_node_delete.
 *
 * If the item is malloc-allocated a free_callback function
 * can be passed to free the memory upon deletion.
 */
BSTreeNode *bs_tree_node_new(void *item, void (*free_callback)(void *));


/*
 * Return a pointer to the node containing the minimum value of the
 * items stored in the subtree rooted at the given node.
 *
 * N.B. Since BSTreeNode is just the physical representation
 * of the tree, the minimum  element is the leftmost node of 
 * thist tree; no logical comparison is required.
 */
BSTreeNode *bs_tree_node_min(BSTreeNode *node);


/*
 * Return a pointer to the node containing the maximum value of the
 * items stored in the subtree rooted at the given node.
 *
 * N.B. Since BSTreeNode is just the physical representation
 * of the tree, the maximum element is the rightmost node of 
 * thist tree; no logical comparison is required.
 */
BSTreeNode *bs_tree_node_max(BSTreeNode *node);


/*
 * Return a pointer to the node containing the successor of the 
 * element stored in the given node.
 * Return NULL if no successor if found.
 *
 * N.B. Since BSTreeNode is just the physical representation
 * of the tree, the successor (predecessor) is computed assuming the invariant
 * binary-search-tree propriety; no logical comparison is required.
 */
BSTreeNode *bs_tree_node_successor(BSTreeNode *node);


/*
 * Return a pointer to the node containing the predecessor of the 
 * element stored in the given node.
 * Return NULL if no predecessor if found.
 *
 * N.B. Since BSTreeNode is just the physical representation
 * of the tree, the predecessor (if present) is computed assuming the invariant
 * binary-search-tree propriety; no logical comparison is required.
 */
BSTreeNode *bs_tree_node_predecessor(BSTreeNode *node);


/*
 * Perform an inorder walk of the tree rooted at the given node,
 * calling *procedure on every item stored in the tree.
 */
void bs_tree_node_inorder_walk(BSTreeNode *node, void (*procedure)(void *));


/*
 * Return a pointer to the item stored in the given node
 */
void *bs_tree_node_get(const BSTreeNode* node);


/*
 * Delete the entire tree rooted at the given node.
 *
 * Every BSTreeNode deleted with this function must have
 * been created with a call to bs_tree_node_new.
 */
void bs_tree_node_delete(BSTreeNode *);


/*
 * BSTree represent the logical structure of a binary
 * search tree. 
 * It's used to properly insert and delete elements into 
 * a binary search tree, maintaining the binary-searh-tree property
 */
typedef struct BSTree BSTree;


/*
 * Create a new Binary Search Tree.
 *
 * Every BSTree created with this function must be 
 * deleted with a call to bs_tree_delete.
 */
BSTree *bs_tree_new(int (*compare)(void*, void*));


/*
 * Return a pointer to the root node of the binary
 * search tree.
 */
BSTreeNode *bs_tree_root(const BSTree *tree);


/*
 * Insert a new node in the binary search tree
 */
void bs_tree_insert(BSTree*, BSTreeNode*);


/*
 * Remove the given node from the binary search tree.
 *
 * N.B. It's the caller's responsibility to guarantee
 * that the node to be removed actually belongs to the 
 * given tree.
 */
void bs_tree_remove(BSTree*, BSTreeNode*);


/*
 * Delete the entire binary search tree.
 *
 * Every BSTree object deleted with this function must have been 
 * created with a call to bs_tree_new.
 */
void bs_tree_delete(BSTree*);

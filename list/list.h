/*
 * ADT List definition interface
 */

typedef struct List List;

/*
 * Return a newly created List.
 *
 * Each List that is created with this function
 * must be deleted with a call to list_delete
 */
List *list_new();


/*
 * Prepend a new element to the List.
 *
 * Return true if the operation is successful
 * false otherwise
 */
_Bool list_prepend(List**, void*);


/*
 * Return a pointer to the node containing
 * the searched element, NULL if it's not present
 */
List *list_find(List*, const void*);


/*
 * Remove the given node from the List and free the 
 * pointer.
 *
 * N.B: a search to check whether the list contains the node
 * is not guaranteed - if the node is not inside the list 
 * it's undefined behavior.
 */
void list_remove(List** , List*);


/*
 * Return true if the list is empty
 */
_Bool list_empty(const List*);


/*
 * Retrieve the item stored at this node.
 *
 * Returns the node itself if it exists, NULL otherwise.
 * The item (which may itself be NULL) is stored in *head.
 */

List *list_get(List*, void **head);


/*
 * Delete a List 
 *
 * The given list must have been created
 * by calling list_new()
 */
void list_delete(List*);


/*
 * ADT List definition interface
 */

typedef struct List List;

/*
 * Allocate and initialize a List.
 *
 * Each List that is allocated with this function
 * must be deleted with a call to list_delete
 */
List *list_new();


/*
 * Prepend a new element to the List.
 *
 * Returns the list if the operation is successful, 
 * NULL otherwise.
 */
List *list_prepend(List**, void*);


/*
 * Return a pointer to the node containing
 * the searched element, NULL if it's not present
 */
List *list_search(List*, const void*);


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
 * Store a pointer to the head item in `*head` and return the List
 * If the list is empty, NULL is stored in `*head` and return NULL
 */
List *list_get(List*, void **head);


/*
 * Delete a List 
 *
 * The given list must have been allocated 
 * by calling list_new()
 */
void list_delete(List*);


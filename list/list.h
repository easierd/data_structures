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
 * Delete a List 
 *
 * The given list must have been allocated 
 * by calling list_new()
 */
void list_delete(List*);


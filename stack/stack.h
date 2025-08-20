/*
 * ADT Stack interface
 */

#pragma once


typedef struct Stack Stack;


/*
 * Create a new stack.
 * Stack returned by this function must be deleted with a call
 * to stack_delete.
 * Return a newly allocated Stack, NULL if allocation fails
 */
Stack *stack_new();


/*
 * Delete the given stack.
 * The Stack argument must have been created with a call 
 * to stack_new
 */
void stack_delete(Stack *);


/*
 * return true if the stack is empty,
 * false otherwise
 */
_Bool stack_empty(Stack *);


/*
 * push elem onto the stack
 * return true if the operation is successful,
 * false otherwise
 */
_Bool stack_push(Stack *, int elem);


/*
 * pop an element from the stack and store it in elem
 * return true if the operation is successful, 
 * false otherwise
 */
_Bool stack_pop(Stack *, int *elem);


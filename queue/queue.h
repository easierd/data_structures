/*
 * ADT Queue interface
 */


#pragma once

#include <stdbool.h>
#include <stdlib.h>


typedef struct queue queue;


/*
 * Allocate a new queue.
 * Every queue created with this function
 * shall be deleted with a call to queue_delete.
 */
queue* queue_new(size_t);


/*
 * Return true if the queue is empty
 * false otherwise
 */
bool queue_empty(const queue*);


/*
 * Return true if the queue is full
 * false otherwise
 */
bool queue_full(const queue*);


/*
 * Enqueue the given element into the queue.
 * The queue stores the pointer as-is; it does not copy the object.
 * Return true if the operation is successful,
 * false if overflow occurred.
 */
bool queue_enqueue(queue*, void*);


/*
 * Dequeue the head element from the queue
 * and store it in the location pointed to 
 * by the given pointer
 * Return true if the operation is successful,
 * false if underflow occurred
 */
bool queue_dequeue(queue*, void**);



/*
 * Remove the given queue.
 * The queue must have been allocated with a 
 * call to queue_new
 */
void queue_delete(queue*);

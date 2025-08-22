/*
 * ADT Queue interface
 */


#pragma once

#include <stdbool.h>
#include <stdlib.h>


typedef struct queue queue;


queue* queue_new(size_t);

bool queue_empty(const queue*);

bool queue_full(const queue*);

bool queue_enqueue(queue*, void*);

bool queue_dequeue(queue*, void**);

void queue_delete(queue*);

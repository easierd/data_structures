#include <stdlib.h>

#include "queue.h"


struct queue {
    void **items;
    size_t head;
    size_t tail;
    size_t sz;
};


queue* queue_new(size_t sz) {
    queue *q = malloc(sizeof(queue));
    q->items = malloc(sizeof(void*) * sz);
    q->head = 0;
    q->tail = 0;
    q->sz = sz;

    return q;
}


bool queue_empty(queue *q) {
    return q->head == q->tail;
}


bool queue_full(queue *q) {
    return q->head == (q->tail + 1) % q->sz;
}


bool queue_enqueue(queue *q, void *item) {
    if (queue_full(q)) {
        return false;
    }

    q->items[q->tail] = item;
    q->tail = (q->tail + 1) % q->sz;
    return true;
}


bool queue_dequeue(queue *q, void **item) {
    if (queue_empty(q)) {
        *item = NULL;
        return false;
    }

    *item = q->items[q->head];
    q->head = (q->head + 1) % q->sz;
    return true;
}


void queue_delete(queue *q) {
    free(q->items);
    free(q);
}

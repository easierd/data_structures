#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define assert_fail(expr) assert(!expr)

int main(void) {
    size_t q_sz = 10;
    queue *q = queue_new(q_sz);
    assert(q != NULL);
    assert(queue_empty(q));

    void *item;
    //assert(!queue_dequeue(q, &item));
    assert_fail(queue_dequeue(q, &item));
    assert(item == NULL);

    assert(queue_enqueue(q, "notable implementation"));
    assert(queue_enqueue(q, "funny theory"));

    assert(queue_dequeue(q, &item));
    assert(strcmp((char *)item, "notable implementation") == 0);
    assert(queue_dequeue(q, &item));
    assert(strcmp((char *)item, "funny theory") == 0);
    assert(queue_empty(q));

    // An array-based queue can store at most q.sz - 1 elements
    for (size_t i = 0; i < q_sz - 1; i++) {
        queue_enqueue(q, &i);
    }
    assert(queue_full(q));
    assert_fail(queue_enqueue(q, "another test"));


    queue_delete(q);
}

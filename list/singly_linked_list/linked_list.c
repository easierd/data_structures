/*
 * Implementation of the ADT List through 
 * a singly linked list
 */
#include<stdlib.h>

#include "../list.h"


struct List{
    void *item;
    struct List* next;
};


List *list_new() {
    return NULL;
}


List *list_prepend(List **l, void* item) {
    List *p = malloc(sizeof(List));
    if (p == NULL) {
        return NULL;
    }
    p->item = item;
    p->next = *l;
    *l = p;
    return *l;
}


void list_delete(List *l) {
    while (l != NULL) {
        List *next = l->next;
        free(l);
        l = next;
    }
}


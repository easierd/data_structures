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


List *list_search(List *l, void *item) {
    while (l) {
        if (l->item == item) {
            return l;
        }
        l = l->next;
    }
    return NULL;
}


/*
 * Return the predecessor of the given item, and store the 
 * node to be removed in removee.
 * NULL if the element is not present
 */
List *find_predecessor(List *l, void *item, List **removee) {
    List *predecessor = NULL;
    while (l) {
       if(l->item == item) {
           *removee = l;
           return predecessor;
       } 
       predecessor = l;
       l = l->next;
    }
    *removee = NULL;
    return NULL;
}


void list_remove(List **l, void* item) {
    List *removee;
    List* predecessor = find_predecessor(*l, item, &removee);
    if (removee) {
        if (predecessor) {
            predecessor->next = removee->next;
        } else {
            *l = removee->next;
        }
        free(removee);
    }
}


void list_delete(List *l) {
    while (l != NULL) {
        List *next = l->next;
        free(l);
        l = next;
    }
}


/*
 * Implementation of the ADT List through 
 * a singly linked list
 */
#include<stdlib.h>
#include<stddef.h>

#include "../list.h"


struct List{
    void *item;
    struct List* next;
};


List *list_new() {
    return NULL;
}


_Bool list_prepend(List **l, void* item) {
    List *p = malloc(sizeof(List));
    if (p == NULL) {
        return 0;
    }
    p->item = item;
    p->next = *l;
    *l = p;
    return 1;
}


List *list_find(List *l, const void *item) {
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
static List *find_predecessor(List *l, List *node) {
    while (l) {
       if(l->next == node) {
           return l;
       } 
       l = l->next;
    }
    return NULL;
}


void list_remove(List **l, List *node) {
    List* predecessor = find_predecessor(*l, node);
    if (predecessor) {
        predecessor->next = node->next;
    } else {
        *l = node->next;
    }
    free(node);
}


_Bool list_empty(const List *l) {
    return l == NULL;
}


List *list_get(List *l, void **head) {
    if (l == NULL) {
        *head = NULL;
    } else {
        *head = l->item;
    }
    return l;
}


void list_delete(List *l) {
    while (l != NULL) {
        List *next = l->next;
        free(l);
        l = next;
    }
}


#ifndef _PQUEUE_H
#define _PQUEUE_H

#define OK = 0;
typedef struct pqentry{
    float priority;
    char* string;
    struct pqentry *prev;
    struct pqentry *next;
}pqentry_t;

// *******************************************************************
typedef struct priorityqueue {
    int size;
    pqentry_t *head;
    pqentry_t *tail;
}priorityqueue_t;

priorityqueue_t* pqueue_create();
void pqueue_insert(priorityqueue_t *pq, char* value, float p);
char* pqueue_extractMin(priorityqueue_t *pq);
void pqueue_decreaseKey(priorityqueue_t *pq, char* value, float p);
void pqueue_remove(priorityqueue_t *pq, char* value);
void pqueue_destroy(priorityqueue_t *pq);

#endif

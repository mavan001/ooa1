#ifndef _PQUEUE_H
#define _PQUEUE_H

    #define OK = 0;

    typedef struct priorityqueue priorityqueue_t;

    priorityqueue_t* pqueue_create();
    void pqueue_insert(priorityqueue_t *pq, char* value, float p);
    char* pqueue_extractMin(priorityqueue_t *pq);
    void pqueue decreaseKey(priorityqueue t *pq, char* value, float p);
    void pqueue remove(priorityqueue t *pq, char* value);
    void pqueue destroy(priorityqueue t *pq);
    
#endif
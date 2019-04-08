#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.h"

// *******************************************************************
struct priorityqueue {
    int top, tail, size;
    char error;
    float *values;
};

// *******************************************************************
priorityqueue_t * pqueue_create() {
    priorityqueue_t *pq;

    pq = (priorityqueue_t *) malloc(sizeof(priorityqueue_t));
    pq->top = NULL;
    pq->tail = NULL;
    pq->size = 0;
    pq->error = OK;
    pq->values = (int *) malloc(sizeof(int) * pq->size);

    return pq;
}

// *******************************************************************
void pqueue_insert(priorityqueue_t *pq, char* value, float p) {
    
}

// *******************************************************************
char* pqueue_extractMin(priorityqueue_t *pq){

}

// *******************************************************************
void pqueue decreaseKey(priorityqueue t *pq, char* value, float p) {

}
    
// *******************************************************************
void pqueue remove(priorityqueue t *pq, char* value) {

}

// *******************************************************************
void pqueue destroy(priorityqueue t *pq) {
    free(pq->values);
    free(pq);
}
    



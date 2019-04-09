#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.h"

// *******************************************************************


// *******************************************************************
priorityqueue_t * pqueue_create() {
    priorityqueue_t *pq;

    pq = (priorityqueue_t *) malloc(sizeof(priorityqueue_t));
    pq->head = NULL;
    pq->tail = NULL;
    pq->size = 0;

    printf("Create: Queue wurde erstellt.\n");
    return pq;
}

// *******************************************************************
void pqueue_insert(priorityqueue_t *pq, char* value, float p) {
    pqentry_t *newElement =(pqentry_t *) malloc(sizeof(pqentry_t));
    pqentry_t *temp;
    newElement->string = value;
    newElement->priority = p;

    if (pq->size == 0) { //PQ ist leer, dann ist newElement erstes und letztes Element
        pq->head = newElement;
        pq->tail = newElement;
        newElement->next = NULL;
        newElement->prev = NULL;
    } else if (p <= pq->head->priority) { //neues Element hat höchste Priorität (kleinere Zahl)
        newElement->next = pq->head;
        newElement->prev = NULL;
        pq->head->prev = newElement;
        pq->head = newElement;
    } else if(p >= pq->tail->priority) { //  kleinste Priorität (hoehere Zahl)
        newElement->next = NULL;
        newElement->prev = pq->tail;
        pq->tail->next = newElement;
        pq->tail = newElement;
    } else {
        temp = pq->head;
        while (temp->priority < p) {
            temp = temp->next;
        }
        newElement->next = temp;
        newElement->prev = temp->prev;
        temp->prev->next = newElement;
        temp->prev = newElement;
    }
    pq->size += 1;

    printf("Insert: ");
    printf(value);
    printf("\n");
}

// *******************************************************************
char* pqueue_extractMin(priorityqueue_t *pq){
    char *minValue;
    if(pq->size != 0) {
        minValue = pq->head->string;
        pqueue_remove(pq, minValue);
        printf("extractMin: ");
        printf(minValue);
        printf("\n");
    } else {
        printf("extractMin: Queue ist leer!\n");
        minValue = "Fehler";
    }
    return minValue;
}

// *******************************************************************
void pqueue_decreaseKey(priorityqueue_t *pq, char* value, float p) {
pqueue_remove(pq, value);
pqueue_insert(pq, value, p);
}

// *******************************************************************
void pqueue_remove(priorityqueue_t *pq, char* value) {
    if (pq->size == 0) { //Queue leer?
        printf("Remove: Queue ist leer.\n");
        return;
    } else if (pq->size == 1) { //Queue hat 1 Element
        if(strcmp(pq->head->string, value) == 0) { // strcmp liefert 0, falls beide Strings gleich sind
            free(pq->head);
            pq->size = 0;
            pq->head = NULL;
            pq->tail = NULL;
        }
        else {
            printf("Remove: Element konnte nicht gefunden werden.\n");
        }
        return;
    }
    if (strcmp(pq->head->string,value) == 0) { //Queue hat mehr als 1 Element und beide Strings sind gleich
        pq->head = pq->head->next;
        free(pq->head->prev);
        pq->head->prev = NULL;
    } else if (strcmp(pq->tail->string,value) == 0) { // Letzte Element der Queue
        pq->tail = pq->tail->prev;
        free(pq->tail->next);
        pq->tail->next = NULL;
    } else { //Queue durchlaufen bis Element gefunden wird
        pqentry_t *temp = pq->head;
        while (temp->next != NULL && strcmp(temp->string, value) != 0) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Remove: Element konnte nicht gefunden werden.\n");
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    pq->size -= 1;
}

// *******************************************************************
void pqueue_destroy(priorityqueue_t *pq) {
if (pq != NULL) {
pqentry_t *temp;
while (pq->head != NULL) { //alle Elemente löschen
temp = pq->head->next;
free(pq->head);
pq->head = temp;
}
free(pq);
    printf("Destroy: Queue erfolgreich gelöscht.\n");
}else {
printf("Destroy: Keine Queue verfügbar.\n");
}
}




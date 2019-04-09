# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "pqueue.h"

# define MAX 50000

char * randomString (int size ) {
    int i ;
    char * str = ( char *) malloc (( size +1)* sizeof ( char ));
    for ( i = 0 ; i < size ; ++ i ) {
        str [ i ] = ( rand () % 26) + 'A';
    }
    str [ size ] = '\0';
    return str ;
}

void test() {
    printf("Test 1: Leere Queue\n");
    priorityqueue_t *pq1 = pqueue_create();
    pqueue_extractMin(pq1);
    pqueue_remove(pq1, "TestTest");
    pqueue_decreaseKey(pq1, "TestTest", 5);
    pqueue_destroy(pq1);

    printf("Test 2\n");
    priorityqueue_t *pq2 = pqueue_create();
    pqueue_insert(pq2, "Hello1" , 5);
    pqueue_insert(pq2, "Hello2" , 20);
    pqueue_insert(pq2, "Hello3" , 2.5);
    pqueue_insert(pq2, "Hello4" , 3);
    pqueue_extractMin(pq2);  //sollte Hello3 ausgeben
    pqueue_remove(pq2, "Hello4");
    pqueue_decreaseKey(pq2, "Hello2", 4);
    pqueue_extractMin(pq2); //sollte Hello2 ausgeben
    pqueue_extractMin(pq2); //sollte Hello1 ausgeben
    pqueue_extractMin(pq2); //sollte Fehler ausgeben
    pqueue_destroy(pq2);
}

int main (int argc , char ** argv ) {
    test();
/*
    int i ;
    char * strings [ MAX ];
    clock_t tic , toc ;

    srand ( time ( NULL ));

    for ( i = 0 ; i < MAX ; ++ i ) {
        strings [ i ] = randomString (8);
    }

    priorityqueue_t * pq = pqueue_create ();

    tic = clock ();
    for ( i = 0 ; i < MAX ; ++ i ) {
        pqueue_insert ( pq , strings [ i ] , rand () % 100);
    }
    toc = clock ();

    printf (" insertion time : %.2f\n", ( float )( toc - tic ) / CLOCKS_PER_SEC );

    tic = clock ();
    for ( i = 0 ; i < MAX ; ++ i ) {
        pqueue_extractMin ( pq );
    }
    toc = clock ();

    printf (" extract time : %.2f\n", ( float )( toc - tic ) / CLOCKS_PER_SEC );

    for ( i = 0 ; i < MAX ; ++ i ) {
        free ( strings [ i ]);
    }
    pqueue_destroy ( pq );
*/
    return 0;
}

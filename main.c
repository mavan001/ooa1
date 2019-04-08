# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "pqueue.h"

# define MAX 100000

char * randomString (int size ) {
    int i ;
    char * str = ( char *) malloc (( size +1)* sizeof ( char ));
    for ( i = 0 ; i < size ; ++ i ) {
        str [ i ] = ( rand () % 26) + ’A’;
    }
    str [ size ] = ’\0 ’;
    return str ;
}

int main (int argc , char ** argv ) {
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

    printf (" insertion time : %.2 f\n", ( float )( toc - tic ) / CLOCKS_PER_SEC );

    tic = clock ();
    for ( i = 0 ; i < MAX ; ++ i ) {
        pqueue_extractMin ( pq );
    }
    toc = clock ();

    printf (" extract time : %.2 f\n", ( float )( toc - tic ) / CLOCKS_PER_SEC );

    for ( i = 0 ; i < MAX ; ++ i ) {
        free ( strings [ i ]);
    }
    pqueue_destroy ( pq );

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "../include/util.h"
#include "../include/list.h"
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"
#include "../include/geometry.h"
#include "../include/algo.h"

int main(int argc, char *argv[]) {
    int N = 6;
    void **A = (void **) calloc(N, sizeof(int *));
    assert(A);

    int *a = (int *) calloc(1, sizeof(int));
    int *b = (int *) calloc(1, sizeof(int));
    int *c = (int *) calloc(1, sizeof(int));
    int *d = (int *) calloc(1, sizeof(int));
    int *e = (int *) calloc(1, sizeof(int));
    int *f = (int *) calloc(1, sizeof(int));

    *a = 0;
    *b = 1;
    *c = 2;
    *d = 3;
    *e = 4;
    *f = 5;

    A[0] = c; // = 2
    A[1] = a; // = 0
    A[2] = e; // = 4
    A[3] = b; // = 1
    A[4] = f; // = 5
    A[5] = d; // = 3

    printf("\nIl y a %d argument et argv[0] : %s\n\n", argc, argv[0]);

    printf("\tLance CBTHeapSort :\n");
    CBTHeapSort(A, N, &intSmallerThan, &viewInt, &free);
    printf("Affiche la table :\n[ ");
    for (int i = 0; i < N; i++) {
        viewInt(A[i]);
        if ((i + 1) < N) {
            printf("; ");
        }
    }
    printf(" ]\n");

    free(A);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return EXIT_SUCCESS;
}
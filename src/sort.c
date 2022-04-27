#include <stdlib.h>
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"

void ArrayHeapSort(void **A, int N,
                   int (*preceed)(const void *, const void *),
                   void (*viewHeapData)(const void *),
                   void (*freeHeapData)(void *)) {
    // TODO ArrayHeapSort : à tester
    assert(A);
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    int i;
    void **ACopie;
    ArrayHeap *AH;

    ACopie = (void **) calloc(N, sizeof(void *));
    assert(ACopie);

    ACopie = A;
    AH = ArrayToArrayHeap(ACopie, N, preceed, viewHeapData, freeHeapData);

    for (i = (N - 1); i >= 0; i--) {
        A[i] = ArrayHeapExtractMin(AH);
    }

    free(ACopie);
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *)) {
    // TODO CBTHeapSort
    assert(A);
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    int i;
    CBTHeap *H;

    H = newCBTHeap(preceed, viewHeapData, freeHeapData);

    for (i = 0; i < N; i++) {
        CBTHeapInsert(H, A[i]);
    }

    for (i = 0; i < N; i++) {
        A[i] = CBTHeapExtractMin(H);
    }
}

void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *)) {
    // TODO SelectionSort : à tester
    int i;
    int j;
    int posMin;
    void *dataSave;

    for (i = 0; i < N - 1; i++) {
        posMin = i;

        for (j = i + 1; j < N; j++) {
            if (preceed(A[j], A[posMin]))
                posMin = j;
        }

        if (posMin != i) {
            dataSave = A[i];
            A[i] = A[posMin];
            A[posMin] = dataSave;
        }
    }
}

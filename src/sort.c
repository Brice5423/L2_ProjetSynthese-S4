#include <stdlib.h>
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"

void ArrayHeapSort(void **A, int N,
                   int (*preceed)(const void *, const void *),
                   void (*viewHeapData)(const void *),
                   void (*freeHeapData)(void *)) {
    assert(A);
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    int i;
    ArrayHeap *AH;

    AH = ArrayToArrayHeap(A, N, preceed, viewHeapData, freeHeapData);

    // Je ne sais pas si c'est normal que ça soit inverser ?
    for (i = (N - 1); i >= 0; i--) {
        A[i] = ArrayHeapExtractMin(AH);
    }

    free(AH);
    AH = NULL;
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *)) {
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

    freeCBTHeap(H, 0);
}

void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *)) {
    int i;
    int j;
    int posMin;
    void *dataSave;

    for (i = 0; i < N - 1; i++) {
        posMin = i;

        for (j = i; j < N; j++) {
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

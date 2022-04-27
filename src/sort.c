#include <stdlib.h>
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"

void ArrayHeapSort(void **A, int N,
                   int (*preceed)(const void *, const void *),
                   void (*viewHeapData)(const void *),
                   void (*freeHeapData)(void *)) {
    // TODO
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *)) {
    // TODO
}

void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *)) {
    int i;
    int j;
    int index;
    void *dataSave;

    for(i = 0; i < N - 1; i++){
        index = i;

        for(j = i + 1; j < N; j++){
            if(preceed(A[index], A[j]))
                index = j;
        }

        if(index != i){
            dataSave = A[i];
            A[i] = A[index];
            A[index] = dataSave;
        }
    }
}
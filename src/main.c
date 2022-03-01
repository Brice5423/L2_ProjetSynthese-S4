#include <stdio.h>
#include <stdlib.h>

#include "../include/util.h"
#include "../include/list.h"
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"
#include "../include/geometry.h"
#include "../include/algo.h"

int main() {
    struct List *L = newList(&viewInt, &freeInt);
    int *data1 = (int *)calloc(1, sizeof(int));
    *data1 = 1;
    int *data2 = (int *)calloc(1, sizeof(int));
    *data2 = 2;
    int *data3 = (int *)calloc(1, sizeof(int));
    *data3 = 3;

    listInsertLast(L, data1);
    viewList(L);

    listInsertFirst(L, data2);
    viewList(L);

    listInsertLast(L, data3);
    viewList(L);
    viewList(L);
    return EXIT_SUCCESS;
}
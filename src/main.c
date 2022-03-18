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
    int *data1 = (int *) calloc(1, sizeof(int));
    *data1 = 1;
    int *data2 = (int *) calloc(1, sizeof(int));
    *data2 = 2;
    int *data3 = (int *) calloc(1, sizeof(int));
    *data3 = 3;

    printf("data 1 : ");
    listInsertLast(L, data1);
    printf("view 1 : ");
    viewList(L);

    printf("data 2 : ");
    listInsertFirst(L, data2);
    printf("view 2 : ");
    viewList(L);

    printf("data 3 : ");
    listInsertLast(L, data3);
    printf("view 3 : ");
    viewList(L);

    return EXIT_SUCCESS;
}
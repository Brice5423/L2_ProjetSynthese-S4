#include <stdlib.h>
#include "tree.h"
#include "heap.h"
#include "sort.h"

void ArrayHeapSort(void** A, int N,
					int (*preceed)(const void*, const void*),
					void (*viewHeapData)(const void*),
					void (*freeHeapData)(void*)) {
	// TODO
}

void CBTHeapSort(void** A, int N,
					int (*preceed)(const void*, const void*),
					void (*viewHeapData)(const void*),
					void (*freeHeapData)(void*)) {
	// TODO
}

void SelectionSort(void** A, int N, int (*preceed)(const void*, const void*)) {
	// TODO
}
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void ShowMessage(char * msg, int interrupt) {
	fprintf(stderr, "%s\n", msg);
	if (interrupt) {
		fprintf(stderr, "An error has occured. The execution of the program will be interrupted!\n");
		exit(1);
	}
}

void viewInt(const void *i) {
	printf("%d", *((int*)i));
}

void freeInt(void * i) {
	free((int*) i);
}

int intSmallerThan(const void* a, const void* b) {
	if (*((int*) a) < *((int*) b))
		return 1;
	else
		return 0;
}

int intGreaterThan(const void* a, const void* b) {
	if (*((int*) a) > *((int*) b))
		return 1;
	else
		return 0;
}
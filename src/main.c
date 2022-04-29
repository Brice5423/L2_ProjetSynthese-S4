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
    const char algo = argv[1][0];

    if (argc == 4) {
        if (algo == 's') {
            SlowConvexHull(argv[2], argv[3]);
            printf("\nOpération bien réussie.\n");
        }
        if (algo == 'r') {
            RapidConvexHull(argv[2], argv[3]);
            printf("\nOpération bien réussie.\n");
        }
        if (algo == 'c') {
            printf("\nUsage : \n\t ./convexhull c infilename outfilename sort\n\t\tsort :\n\t\t\t 1 (CBTHeapSort)\n\t\t\t 2 (ArrayHeapSort)\n\t\t\t 3 (SelectionSort)\n");
        }
    } else if (argc == 5) {
        if (algo == 's') {
            printf("\nUsage : \n\t ./convexhull s infilename outfilename\n");
        }
        if (algo == 'r') {
            printf("\nUsage : \n\t ./convexhull r infilename outfilename\n");
        }
        if (algo == 'c') {
            ConvexHull(argv[2], argv[3], atoi(argv[4]));
            printf("\nOpération bien réussie.\n");
        }
    } else {
        printf("\nUsage : \n\t ./convexhull algo infilename outfilename sort\n\talgo est égale à s (SlowConvexHull) ou c (ConvexHull) ou r (RapidConvexHull)\n\tsort est égale à 1 ou 2 ou 3\n");
    }


    return EXIT_SUCCESS;
}
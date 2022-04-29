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

    if (algo != 'a') {
        if (argc == 4) {
            if (algo == 's') {
                SlowConvexHull(argv[2], argv[3]);
                printf("\nOpération bien réussie.\n");

            } else if (algo == 'r') {
                RapidConvexHull(argv[2], argv[3]);
                printf("\nOpération bien réussie.\n");

            } else if (algo == 'c') {
                printf("\nUsage : \n\t ./convexhull c infilename outfilename sort\n\t\tsort :\n\t\t\t 1 (CBTHeapSort)\n\t\t\t 2 (ArrayHeapSort)\n\t\t\t 3 (SelectionSort)\n");
            }

        } else if (argc == 5) {
            if (algo == 's') {
                printf("\nUsage : \n\t ./convexhull s infilename outfilename\n");

            } else if (algo == 'r') {
                printf("\nUsage : \n\t ./convexhull r infilename outfilename\n");

            } else if (algo == 'c') {
                ConvexHull(argv[2], argv[3], atoi(argv[4]));
                printf("\nOpération bien réussie.\n");
            }

        } else {
            printf("\nUsage : \n\t ./convexhull algo infilename outfilename sort\n\talgo est égale à s (SlowConvexHull) ou c (ConvexHull) ou r (RapidConvexHull)\n\tsort est égale à 1 ou 2 ou 3\n");
        }

    } else {
        RapidConvexHull("data/data1", "batterieTest/convex/rapidConvex_Data1");
        RapidConvexHull("data/data2", "batterieTest/convex/rapidConvex_Data2");
        RapidConvexHull("data/data3", "batterieTest/convex/rapidConvex_Data3");
        RapidConvexHull("data/data4", "batterieTest/convex/rapidConvex_Data4");

        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy1", 1);
        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy2", 2);
        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy3", 3);

        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy1", 1);
        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy2", 2);
        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy3", 3);

        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy1", 1);
        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy2", 2);
        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy3", 3);

        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy1", 1);
        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy2", 2);
        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy3", 3);

        SlowConvexHull("data/data1", "batterieTest/convex/slowConvex_Data1");
        SlowConvexHull("data/data2", "batterieTest/convex/slowConvex_Data2");
        SlowConvexHull("data/data3", "batterieTest/convex/slowConvex_Data3");
        SlowConvexHull("data/data4", "batterieTest/convex/slowConvex_Data4");
    }


    return EXIT_SUCCESS;
}
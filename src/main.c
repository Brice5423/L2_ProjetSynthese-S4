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
    printf("Il y a %d argument et argv[0] : %s\n\n", argc, argv[0]);

    ConvexHull("data/data1", "batterieTest/convex/convex1", 1);
    ConvexHull("data/data1", "batterieTest/convex/convex2", 2);
    ConvexHull("data/data1", "batterieTest/convex/convex3", 3);

    /*ConvexHull("data/data2", "batterieTest/convex/convex1", 1);
    ConvexHull("data/data2", "batterieTest/convex/convex2", 2);
    ConvexHull("data/data2", "batterieTest/convex/convex3", 3);*/

    /*ConvexHull("data/data3", "batterieTest/convex/convex1", 1);
    ConvexHull("data/data3", "batterieTest/convex/convex2", 2);
    ConvexHull("data/data3", "batterieTest/convex/convex3", 3);*/

    /*ConvexHull("data/data4", "batterieTest/convex/convex1", 1);
    ConvexHull("data/data4", "batterieTest/convex/convex2", 2);
    ConvexHull("data/data4", "batterieTest/convex/convex3", 3);*/

    return EXIT_SUCCESS;
}
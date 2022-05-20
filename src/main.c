#include <stdio.h>
#include <stdlib.h>

#include "../include/util.h"
#include "../include/list.h"
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/sort.h"
#include "../include/geometry.h"
#include "../include/algo.h"

#include <time.h>

int main(int argc, char *argv[]) {
    const char algo = argv[1][0];

    if (algo == 'a') {
        /* Ce qui est en commentaire ci-dessous sont les cas qui pose problème.
         * On ne sait pas s'ils ont une fin, mais ce qui est sur,
         * c'est que l'utilisation de la RAM fait que d'augmenter !!!
         * */
        clock_t start;
        clock_t end;

        printf("\t\t----- RapidConvexHull -----\n");

        start = clock();
        RapidConvexHull("data/data1", "batterieTest/convex/rapidConvex_Data1");
        end = clock();
        printf("Time used data1 : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        //RapidConvexHull("data/data2", "batterieTest/convex/rapidConvex_Data2");
        end = clock();
        printf("Time used data2 : \t%lf sec \t( INFINI )\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        RapidConvexHull("data/data3", "batterieTest/convex/rapidConvex_Data3");
        end = clock();
        printf("Time used data3 : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        RapidConvexHull("data/data4", "batterieTest/convex/rapidConvex_Data4");
        end = clock();
        printf("Time used data4 : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\n\t\t----- ConvexHull -----\n");


        printf("\tData 1 :\n");

        start = clock();
        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy1", 1);
        end = clock();
        printf("Time used CBTHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy2", 2);
        end = clock();
        printf("Time used ArrayHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data1", "batterieTest/convex/convex_Data1_SortBy3", 3);
        end = clock();
        printf("Time used SelectionSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\tData 2 :\n");

        start = clock();
        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy1", 1);
        end = clock();
        printf("Time used CBTHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy2", 2);
        end = clock();
        printf("Time used ArrayHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data2", "batterieTest/convex/convex_Data2_SortBy3", 3);
        end = clock();
        printf("Time used SelectionSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\tData 3 :\n");

        start = clock();
        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy1", 1);
        end = clock();
        printf("Time used CBTHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy2", 2);
        end = clock();
        printf("Time used ArrayHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data3", "batterieTest/convex/convex_Data3_SortBy3", 3);
        end = clock();
        printf("Time used SelectionSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\tData 4 :\n");

        start = clock();
        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy1", 1);
        end = clock();
        printf("Time used CBTHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy2", 2);
        end = clock();
        printf("Time used ArrayHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/data4", "batterieTest/convex/convex_Data4_SortBy3", 3);
        end = clock();
        printf("Time used SelectionSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\n\t\t----- SlowConvexHull -----\n");

        start = clock();
        SlowConvexHull("data/data1", "batterieTest/convex/slowConvex_Data1");
        end = clock();
        printf("Time used data1 : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        //SlowConvexHull("data/data2", "batterieTest/convex/slowConvex_Data2");
        end = clock();
        printf("Time used data2 : \t%lf sec \t( INFINI )\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        //SlowConvexHull("data/data3", "batterieTest/convex/slowConvex_Data3");
        end = clock();
        printf("Time used data3 : \t%lf sec \t( INFINI )\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        //SlowConvexHull("data/data4", "batterieTest/convex/slowConvex_Data4");
        end = clock();
        printf("Time used data4 : \t%lf sec \t( INFINI )\n", (((double) (end - start)) / CLOCKS_PER_SEC));


    } else if (algo == 't')  {
        /**
         * Permet de faire les tests de temps d'exécution avec différente data.
         * On a fait ça à cause des problèmes qu'on peut avoir. On est obligé de test un par un les datas.
         */
        clock_t start;
        clock_t end;
        FILE *fp;
        int *N = (int *) calloc(1, sizeof(int));

        fp = fopen("data/testData/dataTest", "r");
        assert(fp);
        fscanf(fp, "%d", N);
        fclose(fp);

        printf("\nNombre de point dans le fichier : \t%d\n", *N);


        printf("\n\t\t----- RapidConvexHull -----\n");

        start = clock();
        RapidConvexHull("data/testData/dataTest", "batterieTest/convex/rapidConvex_DataTest");
        end = clock();
        printf("Time used : \t\t\t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\n\t\t----- ConvexHull -----\n");

        start = clock();
        ConvexHull("data/testData/dataTest", "batterieTest/convex/convex_DataTest_SortBy1", 1);
        end = clock();
        printf("Time used CBTHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/testData/dataTest", "batterieTest/convex/convex_DataTest_SortBy2", 2);
        end = clock();
        printf("Time used ArrayHeapSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));

        start = clock();
        ConvexHull("data/testData/dataTest", "batterieTest/convex/convex_DataTest_SortBy3", 3);
        end = clock();
        printf("Time used SelectionSort : \t%lf sec\n", (((double) (end - start)) / CLOCKS_PER_SEC));


        printf("\n\t\t----- SlowConvexHull -----\n");

        start = clock();
        SlowConvexHull("data/testData/dataTest", "batterieTest/convex/slowConvex_DataTest");
        end = clock();
        printf("Time used : \t\t\t%lf sec\n\n", (((double) (end - start)) / CLOCKS_PER_SEC));

    } else {
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
    }


    return EXIT_SUCCESS;
}
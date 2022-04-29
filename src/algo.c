#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/algo.h"
#include "../include/geometry.h"
#include "../include/list.h"
#include "../include/tree.h"
#include "../include/util.h"
#include "../include/heap.h"
#include "../include/sort.h"

/**
 * @brief Réalise la lecture d'un ensemble des points à partir du fichier
 * \p filename.
 * Renvoie 2 paramètres : un tableau contenant les points du fichier
 * \p filename, le nombre \p N de ces points.
 *
 * @param[in] filename le nom du fichier qui contient les points d'entrée.
 * @param[out] N le nombre des points dans le fichier \p filename
 * (paramètre de sortie).
 * @return Point** le tableau avec les points du fichier \p filename.
 */

static Point **readInstance(const char *filename, int *N) {
    assert(filename);

    FILE *fp;
    Point **buffer;
    long long int x;
    long long int y;

    fp = fopen(filename, "r");
    assert(fp);

    fscanf(fp, "%d", N);
    buffer = (Point **) calloc(*N, sizeof(Point *));
    assert(buffer);

    for (int i = 0; i < *N; i++) {
        fscanf(fp, "%lld %lld", &x, &y);
        buffer[i] = newPoint(x, y);
    }

    fclose(fp);
    return buffer;
}

/**
 * @brief Réalise l'écriture de l'ensemble des points de la liste \p L
 * dans un fichier avec le nom \p filename.
 *
 * @param[in] filename le nom du fichier d'écriture.
 * @param[in] L la liste des points à écrire dans le fichier \p filename.
 */
static void writeSolution(const char *filename, List *L) {
    assert(filename);
    assert(L);

    int i;
    FILE *fp;
    LNode *node;

    fp = fopen(filename, "w");
    assert(fp);
    node = Head(L);
    assert(node);

    for (i = 0; i < getListSize(L); i++) { // getListSize(L) - 1
        fprintf(fp, "%lld %lld \n", X(getLNodeData(node)), Y(getLNodeData(node)));
        node = Successor(node);
    }

    fclose(fp);
}

/**
 * @brief Transforme la liste des arcs \p dedges décrivant les arêtes
 * du polygone de l'enveloppe convexe à une liste des poins ordonnés
 * dans le sens horaire.
 *
 * @param[in] edges la liste des arcs de l'enveloppe convexe
 * @return List* la liste des points de l'enveloppe convexe dans le sens
 * horaire
 */
static List *DedgesToClockwisePoints(List *dedges) {
    assert(dedges);

    LNode *node;
    List *lstPoint;
    Point *P;

    node = Head(dedges);
    lstPoint = newList(&viewPoint, &freePoint);

    //listInsertFirst(lstPoint, getOrigin(getLNodeData(node)));
    listInsertFirst(lstPoint, getOrigin(getLNodeData(node)));

    while (Successor(node)) {
        Point *A;
        Point *B;

        A = getDestination(getLNodeData(node));
        B = getOrigin(getLNodeData(Successor(node)));

        if (A != B) {
            void *data;

            data = listRemoveNode(dedges, Successor(node));
            listInsertLast(dedges, data);

        } else {
            listInsertFirst(lstPoint, B);
            node = Successor(node);
        }
    }

    P = getDestination(getLNodeData(node));

    if (P != getLNodeData(Head(lstPoint))) {
        listInsertLast(lstPoint, P);
    }

    return lstPoint;
}

/**
 * @brief Compare le points \p a et \p b. Fonction créée par Matthieu FRITSCH
 *
 * @param[in] a
 * @param[in] b
 * @return int si l'abscisse de \p a est différente de l'abscisse de \p b
 * renvoie 1, sinon renvoie 0. Dans le cas d'égalité, si l'ordonnée de \p a
 * est différente de l'ordonnée de \p b renvoie 1, sinon renvoie 0.
 */

int nonEqualsPoint(const void *a, const void *b) {
    //TODO : tester nonEqualsPoint
    if (X(a) != X(b)) {
        return 1;

    } else {
        if (Y(a) != Y(b)) {
            return 1;
        }
    }

    return 0;
}

void SlowConvexHull(const char *infilename, const char *outfilename) {
    int N;
    int ok;
    List *E;
    Point **tab;

    ok = 0;

    E = newList(&viewPoint, &freePoint);
    tab = readInstance(infilename, &N);

    for (int i = 0; i < N; i++) {
        Point *A;

        A = tab[i];

        for (int j = 0; j < N; j++) {
            Point *B;

            B = tab[j];
            ok = 1;

            if (A != B) {
                for (int k = 0; k < N; k++) {
                    Point *P;

                    P = tab[k];
                    if ((nonEqualsPoint(P, A) == 1) && (nonEqualsPoint(P, B) == 1)) {
                        if ((onLeft(A, B, P) || (isIncluded(A, B, P)))) {
                            ok = 0;
                        }
                    }
                }

                if (ok == 1) {
                    LNode *node;

                    node = newLNode(newDEdge(A, B));
                    listInsertLast(E, getLNodeData(node));
                }
            }
        }
    }

    writeSolution(outfilename, DedgesToClockwisePoints(E));
}

/**
 * @brief Compare le points \p a et \p b.
 *
 * @param[in] a
 * @param[in] b
 * @return int si l'abscisse de \p a est plus petite que l'abscisse de \p b
 * renvoie 1, sinon renvoie 0. Dans le cas d'égalité, si l'ordonnée de \p a
 * est plus petite que l'ordonnée de \p b renvoie 1, sinon renvoie 0.
 */
static int smallerPoint(const void *a, const void *b) {
    //TODO tester smallerPoint
    if (X(a) < X(b)) {
        return 1;

    } else if (X(a) == X(b)) {
        if (Y(a) < Y(b)) {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Compare le points \p a et \p b.
 *
 * @param[in] a
 * @param[in] b
 * @return int si l'abscisse de \p a est plus grande que l'abscisse de \p b
 * renvoie 1, sinon renvoie 0. Dans le cas d'égalité, si l'ordonnée de \p a
 * est plus grande que l'ordonnée de \p b renvoie 1, sinon renvoie 0.
 */
static int biggerPoint(const void *a, const void *b) {
    //TODO tester biggerPoint
    if (X(a) > X(b)) {
        return 1;

    } else if (X(a) == X(b)) {
        if (Y(a) > Y(b)) {
            return 1;
        }
    }

    return 0;
}

void ConvexHull(const char *infilename, const char *outfilename, int sortby) {
    //TODO tester ConvexHull 
    assert(infilename);
    assert(outfilename);
    assert(sortby == 1 || sortby == 2 || sortby == 3);

    int i;
    int N;

    List *H;
    List *HSup;
    List *HInf;
    Point **tab;

    Point *PS;
    Point *PR;
    Point *PQ;

    tab = readInstance(infilename, &N);
    H = newList(&viewPoint, &freePoint);
    HSup = newList(&viewPoint, &freePoint);
    HInf = newList(&viewPoint, &freePoint);

    if (sortby == 1) {
        ArrayHeapSort(((void **) tab), N, &biggerPoint, &viewPoint, &freePoint);

    } else if (sortby == 2) {
        CBTHeapSort(((void **) tab), N, &smallerPoint, &viewPoint, &freePoint);

    } else {
        SelectionSort(((void **) tab), N, &smallerPoint);
    }

    /* ----- ----- Liste de points de l’enveloppe supérieure ----- ----- */

    for (i = 0; i < 2; i++) {
        listInsertLast(HSup, tab[i]);
    }

    for (i = 2; i < N; i++) {
        listInsertLast(HSup, tab[i]);

        PQ = getLNodeData(Predecessor(Predecessor(Tail(HSup))));
        PR = getLNodeData(Predecessor(Tail(HSup)));
        PS = getLNodeData(Tail(HSup));

        while ((getListSize(HSup) > 2) && onLeft(PQ, PR, PS)) {
            listRemoveNode(HSup, Predecessor(Tail(HSup)));
        }
    }

    /* ----- ----- Liste de points de l’enveloppe inférieure ----- ----- */

    for (i = (N - 1); i > (N - 3); i--) {
        listInsertLast(HInf, tab[i]);
    }

    for (i = (N - 3); i >= 0; i--) {
        listInsertLast(HInf, tab[i]);

        PQ = getLNodeData(Predecessor(Predecessor(Tail(HInf))));
        PR = getLNodeData(Predecessor(Tail(HInf)));
        PS = getLNodeData(Tail(HInf));

        while ((getListSize(HInf) > 2) && onLeft(PQ, PR, PS)) {
            listRemoveNode(HInf, Predecessor(Tail(HInf)));
        }
    }

    listRemoveLast(HSup);
    listRemoveLast(HInf);

    H = listConcatenate(HSup, HInf);

    writeSolution(outfilename, H);
}

void RapidConvexHull(const char *infilename, const char *outfilename) {
    // TODO RapidConvexHull le faire
    assert(infilename);
    assert(outfilename);
}

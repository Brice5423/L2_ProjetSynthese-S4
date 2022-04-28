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

static Point ** readInstance(const char *filename, int *N) {
    FILE *fp;

    fp = fopen(filename, "r");
    if(!fp)
        printf("marche pas");

    fscanf(fp, "%d", &N);
    Point **buffer = (Point **) calloc(N, sizeof(Point *));

    long long int x, y;

    for(int i = 0; i < N; i++){
        fscanf(fp, "%lld %lld", &x, &y);
        buffer[i] = newPoint(x,y);
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
    printf("avant file\n");
    FILE *fp;
    fp = fopen(filename, "w");
    if(!fp)
        ShowMessage("fopen write", 1);

    printf("avant node\n");
    LNode *node;
    node = Head(L);

    for(int i = 0; i < getListSize(L); i++){
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
    assert(dedges != NULL);

    LNode *node;
    node = Head(dedges);
    List *lstPoint;
    lstPoint = newList(viewPoint, freePoint);

    listInsertFirst(lstPoint, getOrigin(getLNodeData(node)));

    while(Successor(node) != NULL){
        Point *A = getDestination(getLNodeData(node));
        Point *B = getOrigin(getLNodeData(Successor(node)));
        if(A != B){
            void *data = listRemoveNode(dedges, Successor(node));
            listInsertLast(dedges, data);
        }
        else{
            listInsertFirst(lstPoint, B);
            node = Successor(node);
        }
    }
    Point *P = getDestination(getLNodeData(node));
    if(P != getLNodeData(Head(lstPoint))){
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

int nonEqualsPoint(const void *a, const void *b){
    //TODO : tester nonEqualsPoint
    if(X(a) != X(b)){
        return 1;
    }
    else if(X(a) == X(b)){
        if(Y(a) != Y(b)){
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

void SlowConvexHull(const char *infilename, const char *outfilename) {
    printf("avant création");
    List *E = calloc(1, sizeof(List*));


    int N;
    printf("avant read");
    Point **tab;
    tab = readInstance(infilename, &N);

    int ok;

    for(int i = 0; i < N; i++){
        Point *A = newPoint(tab[i]->x, tab[i]->y);
        for(int j = 0; j < N; j++){
            Point *B = newPoint(tab[j]->x, tab[j]->y);
            ok = 1;
            for(int k = 0; k < N; k++){
                Point *P = newPoint(tab[k]->x, tab[k]->y);
                if((nonEqualsPoint(P, A) == 1) && (nonEqualsPoint(P, B) == 1)){
                    if((onLeft(A, B, P) || (isIncluded(A, B, P)))){
                        ok = 0;
                    }
                }
            }
            if(ok == 1){
                LNode *node;
                node = newLNode(newDEdge(A, B));
                listInsertLast(E, getLNodeData(node));
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
    if(X(a) < X(b))return 1;
    else if (X(a) == X(b)) {
        if (Y(a) < Y(b))
            return 1;
        else
            return 0;
    }
    else
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
    if(X(a) > X(b))
        return 1;
    else if (X(a) == X(b)) {
        if (Y(a) > Y(b))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

void ConvexHull(const char *infilename, const char *outfilename, int sortby) {
    //TODO
    assert(sortby == 1 || sortby == 2 || sortby == 3);
}

void RapidConvexHull(const char *infilename, const char *outfilename) {
    // TODO
}
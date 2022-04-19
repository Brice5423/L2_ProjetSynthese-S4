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
    //TODO : tester readInstance, demander au prof
    FILE *fp;
    fp = fopen(filename, "r");
    if(!fp)
        ShowMessage("fopen", 0);
    Point *buffer = calloc(1, sizeof(Point));
    N = atoi((const char *) fscanf(fp, 1, buffer));
    for(int i = 2; i <= sizeof(filename); i++){
        fscanf(fp, "%[^\n]", buffer);
    }
    fclose(fp);
    return (Point **) buffer;
}

/**
 * @brief Réalise l'écriture de l'ensemble des points de la liste \p L
 * dans un fichier avec le nom \p filename.
 *
 * @param[in] filename le nom du fichier d'écriture.
 * @param[in] L la liste des points à écrire dans le fichier \p filename.
 */
static void writeSolution(const char *filename, List *L) {
    //TODO : tester writeSolution, demander au prof
    FILE *fp;
    fp = fopen(filename, "wb");
    if(!fp)
        ShowMessage("fopen", 0);
    for(int i = 1; i <= getListSize(L); i++)
        fprintf(fp, "%s", L);
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
    // TODO : je ne comprends pas comment la faire
}

void SlowConvexHull(const char *infilename, const char *outfilename) {
    // TODO
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
    if(X(a) < X(b))
        return 1;
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
    // TODO
}

void RapidConvexHull(const char *infilename, const char *outfilename) {
    // TODO
}
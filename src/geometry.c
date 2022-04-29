#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/geometry.h"
#include "../include/util.h"


Point *newPoint(long long int x, long long int y) {
    Point *P;

    P = (Point *) calloc(1, sizeof(Point));
    assert(P);

    P->x = x;
    P->y = y;

    return P;
}

long long int X(const Point *P) {
    return P->x;
}

long long int Y(const Point *P) {
    return P->y;
}

void viewPoint(const void *P) {
    printf("\nPoint ( Abscisse : %lld ; Ordonnée : %lld )\n", X((Point *) P), Y((Point *) P));
}

void freePoint(void *P) {
    free(P);
    P = NULL;
}

/* < 0 : à droite
 * > 0 : à gauche
 * = 0 : colinéaire
 * A : origin
 * B: destination
 */
int onRight(const Point *origin, const Point *destination, const Point *P) {
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) < 0) {
        return 1;

    } else {
        return 0;
    }
}

int onLeft(const Point *origin, const Point *destination, const Point *P) {
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) > 0) {
        return 1;

    } else {
        return 0;
    }
}

int collinear(const Point *origin, const Point *destination, const Point *P) {
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) == 0) {
        return 1;

    } else {
        return 0;
    }
}

int isIncluded(const Point *origin, const Point *destination, const Point *P) {
    // verifier si P est colinéaire
    if (collinear(origin, destination, P)) {
        // si colinéaire alors vérifier que l'abscisse de P est inférieur à l'abscisse de destination et superieur à l'abscisse de l'origine
        if ((X(P) < X(destination)) && (X(P) > X(origin))) {
            // si c'est vrai alors faire pareil pour l'ordonnée
            if ((Y(P) < Y(destination)) && (Y(P) > Y(origin))) {
                // si tout est vrai alors on retourne 1
                return 1;
            }
        }
    }

    return 0;
}

DEdge *newDEdge(Point *origin, Point *destination) {
    DEdge *DE;

    DE = (DEdge *) calloc(1, sizeof(DEdge));
    assert(DE);

    DE->origin = origin;
    DE->destination = destination;

    return DE;
}

Point *getOrigin(const DEdge *DE) {
    return DE->origin;
}

Point *getDestination(const DEdge *DE) {
    return DE->destination;
}

void viewDEdge(const void *DE) {
    printf("\nOrigine de l'arc : \n");
    viewPoint(getOrigin(DE));
    printf("\nDestination de l'arc : ");
    viewPoint(getDestination(DE));
}

void freeDEdge(void *DE) {
    free(getDestination(DE));
    free(getOrigin(DE));
    free(DE);
    DE = NULL;
}

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../include/tree.h"
#include "../include/heap.h"
#include "../include/util.h"

/**********************************************************************************
 * ARRAY HEAP
 **********************************************************************************/

int getAHMaxSize(const ArrayHeap *AH) {
    //TODO
}

int getAHActualSize(const ArrayHeap *AH) {
    //TODO
}

void *getAHNodeAt(const ArrayHeap *AH, int pos) {
    //TODO
}

void decreaseAHActualSize(ArrayHeap *AH) {
    //TODO
}

void setAHNodeAt(ArrayHeap *AH, int position, void *newData) {
    // TODO
}

/**
 * @brief Corrige la position de l'élément de la position \p pos
 * du tas \p AH en le comparant avec ses fils et en l'échangeant avec
 * le fils de la plus grande priorité si nécessaire.
 *
 * Procédure récursive.
 * 
 * @param[in] AH 
 * @param[in] pos L'indice de la valeur en mouvement vers le bas.
 */
static void updateArrayHeapDownwards(ArrayHeap *AH, int pos) {
    // TODO
}

ArrayHeap *ArrayToArrayHeap(void **A, int N,
                            int (*preceed)(const void *, const void *),
                            void (*viewHeapData)(const void *),
                            void (*freeHeapData)(void *)) {
    // TODO
}

void viewArrayHeap(const ArrayHeap *AH) {
    // TODO
}

void freeArrayHeap(ArrayHeap *AH, int deletenode) {
    // TODO
}

void *ArrayHeapExtractMin(ArrayHeap *AH) {
    assert(getAHActualSize(AH) > 0);
    // TODO
}

/**********************************************************************************
 * COMPLETE BINARY TREE HEAP
 **********************************************************************************/

CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
                    void (*viewHeapData)(const void *),
                    void (*freeHeapData)(void *)) {
    // TODO
}

CBTree *getCBTree(const CBTHeap *H) {
    // TODO
}

/**
 * @brief Corrige la position du nœud à la position \p pos
 * de l'arbre raciné à \p node en le comparant avec son père
 * et en l'échangeant avec lui si nécessaire.
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.
 *
 * Procédure récursive. En descendant, on cherche le premier nœud
 * à corriger qui se trouve dans la position \p pos (de la même façon
 * que dans insertAfterLastTNode). En remontant, on corrige en échangeant
 * avec le père, si besoin.
 * 
 * @param[in] node 
 * @param[in] position 
 * @param[in] preceed 
 */
static void updateCBTHeapUpwards(TNode *node, int pos, int (*preceed)(const void *, const void *)) {
    // TODO
}

void CBTHeapInsert(CBTHeap *H, void *data) {
    // TODO
}

/**
 * @brief Corrige la position du nœud \p node en le comparant avec ses fils
 * et en l'échangeant avec le fils de la plus grande priorité si nécessaire.
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.
 *
 * Procédure récursive.
 *
 * NB: Le sous-arbre avec racine \p node ne peut pas être vide.
 * 
 * @param[in] node 
 * @param[in] preceed 
 */
static void updateCBTHeapDownwards(TNode *node, int (*preceed)(const void *, const void *)) {
    assert(node);
    // TODO
}

void *CBTHeapExtractMin(CBTHeap *H) {
    assert(Root(getCBTree(H)));
    // TODO
}

void viewCBTHeap(const CBTHeap *H) {
    // TODO
}

void freeCBTHeap(CBTHeap *H, int deletenode) {
    // TODO
}
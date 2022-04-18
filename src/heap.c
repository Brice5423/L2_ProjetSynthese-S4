#include "../include/heap.h"

/**********************************************************************************
 * ARRAY HEAP TODO BriceBriçou : liste de tas ======================================
 **********************************************************************************/

int getAHMaxSize(const ArrayHeap *AH) {
    assert(AH);
    return AH->MAX;
}

int getAHActualSize(const ArrayHeap *AH) {
    assert(AH);
    return AH->N;
}

void *getAHNodeAt(const ArrayHeap *AH, int pos) {
    assert(AH);
    return AH->A[pos];
}

void decreaseAHActualSize(ArrayHeap *AH) {
    assert(AH);
    AH->N--;
}

void setAHNodeAt(ArrayHeap *AH, int position, void *newData) {
    assert(AH);
    AH->A[position] = newData;
}

/**
 * @brief Corrige la position de l'élément de la position \p pos
 * du tas \p AH en le comparant avec ses fils et en l'échangeant avec
 * le fils de la plus grande priorité si nécessaire.\n\n
 *
 * Procédure récursive.
 * 
 * @param[in] AH 
 * @param[in] pos L'indice de la valeur en mouvement vers le bas.
 */
static void updateArrayHeapDownwards(ArrayHeap *AH, int pos) {
    // TODO updateArrayHeapDownwards : à tester
    assert(AH);
    assert(getAHActualSize(AH));

    int posFg;
    int posFd;
    void *dataFgSave;

    posFg = 2 * pos + 1;
    posFd = 2 * pos + 2;

    if (posFd < getAHActualSize(AH)) {
        if (AH->preceed(getAHNodeAt(AH, posFd), getAHNodeAt(AH, posFg))) {
            dataFgSave = getAHNodeAt(AH, posFg);
            setAHNodeAt(AH, posFg, getAHNodeAt(AH, posFd));
            setAHNodeAt(AH, posFd, dataFgSave);
        }
    }

    if (AH->preceed(getAHNodeAt(AH, posFg), getAHNodeAt(AH, pos))) {
        dataFgSave = getAHNodeAt(AH, posFg);
        setAHNodeAt(AH, posFg, getAHNodeAt(AH, pos));
        setAHNodeAt(AH, pos, dataFgSave);

        if (posFd < getAHActualSize(AH)) {
            if (AH->preceed(getAHNodeAt(AH, posFd), getAHNodeAt(AH, posFg))) {
                dataFgSave = getAHNodeAt(AH, posFg);
                setAHNodeAt(AH, posFg, getAHNodeAt(AH, posFd));
                setAHNodeAt(AH, posFd, dataFgSave);
            }
        }
    }

    pos++;
    if ((pos + 1) < getAHActualSize(AH)) {
        updateArrayHeapDownwards(AH, pos);
    }
}

ArrayHeap *ArrayToArrayHeap(void **A, int N,
                            int (*preceed)(const void *, const void *),
                            void (*viewHeapData)(const void *),
                            void (*freeHeapData)(void *)) {
    // TODO ArrayToArrayHeap : à tester
    assert(A);
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    ArrayHeap *AH;

    AH = (ArrayHeap *) calloc(1, sizeof(ArrayHeap));
    assert(AH);

    AH->A = A;
    AH->MAX = 1048576; // = 2^20 TODO AH->MAX = ?
    AH->N = N;
    AH->preceed = preceed;
    AH->viewHeapData = viewHeapData;
    AH->freeHeapData = freeHeapData;

    return AH;
}

void viewArrayHeap(const ArrayHeap *AH) {
    // TODO viewArrayHeap : à tester
    assert(AH);

    printf("[ ");
    for (int i = 0; i < getAHActualSize(AH); i++) {
        AH->viewHeapData(getAHNodeAt(AH, i));
        if ((i + 1) < getAHActualSize(AH)) {
            printf("; ");
        }
    }
    printf(" ]");
}

void freeArrayHeap(ArrayHeap *AH, int deletedata) {
    // TODO freeArrayHeap : à tester
    assert(AH);

    if (deletedata == 1) {
        for (int i = 0; i < getAHActualSize(AH); i++) {
            AH->freeHeapData(getAHNodeAt(AH, i));
        }
        free(*AH->A);
        free(AH->A);
    }

    AH->MAX = 0;
    AH->N = 0;
    AH->preceed = NULL;
    AH->viewHeapData = NULL;
    AH->freeHeapData = NULL;

    free(AH);
}

void *ArrayHeapExtractMin(ArrayHeap *AH) {
    // TODO ArrayHeapExtractMin : à tester (à voir si c'est ce qu'il demande de faire)
    assert(AH);
    assert(getAHActualSize(AH));

    int posData;
    void *data;

    // Organiser l'arrayHeap AH
    updateArrayHeapDownwards(AH, 0);

    // Récupérer la position et la data, et la retire de la l'array
    posData = getAHActualSize(AH) - 1;
    data = getAHNodeAt(AH, posData);
    setAHNodeAt(AH, posData, NULL);
    decreaseAHActualSize(AH);

    return data;
}

/**********************************************************************************
 * COMPLETE BINARY TREE HEAP TODO BriceBriçou : Arbre binaire complet de tas ==============
 **********************************************************************************/

CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
                    void (*viewHeapData)(const void *),
                    void (*freeHeapData)(void *)) {
    // TODO newCBTHeap
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    return NULL;
}

CBTree *getCBTree(const CBTHeap *H) {
    assert(H);
    return H->T;
}

/**
 * @brief Corrige la position du nœud à la position \p pos
 * de l'arbre raciné à \p node en le comparant avec son père
 * et en l'échangeant avec lui si nécessaire.\n
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.\n\n
 *
 * Procédure récursive. En descendant, on cherche le premier nœud
 * à corriger qui se trouve dans la position \p pos (de la même façon
 * que dans insertAfterLastTNode).\n
 * En remontant, on corrige en échangeant avec le père, si besoin.
 * 
 * @param[in] node 
 * @param[in] position 
 * @param[in] preceed 
 */
static void updateCBTHeapUpwards(TNode *node, int pos, int (*preceed)(const void *, const void *)) {
    // TODO updateCBTHeapUpwards
    assert(node);
    assert(preceed);


}

void CBTHeapInsert(CBTHeap *H, void *data) {
    // TODO CBTHeapInsert
    assert(H);


}

/**
 * @brief Corrige la position du nœud \p node en le comparant avec ses fils
 * et en l'échangeant avec le fils de la plus grande priorité si nécessaire.\n
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.\n\n
 *
 * Procédure récursive.\n\n
 *
 * NB: Le sous-arbre avec racine \p node ne peut pas être vide.
 * 
 * @param[in] node 
 * @param[in] preceed 
 */
static void updateCBTHeapDownwards(TNode *node, int (*preceed)(const void *, const void *)) {
    // TODO updateCBTHeapDownwards
    assert(node);
    assert(preceed);


}

void *CBTHeapExtractMin(CBTHeap *H) {
    // TODO CBTHeapExtractMin
    assert(H);


}

void viewCBTHeap(const CBTHeap *H) {
    // TODO viewCBTHeap
    assert(H);


}

void freeCBTHeap(CBTHeap *H, int deletenode) {
    // TODO freeCBTHeap
    assert(H);


}
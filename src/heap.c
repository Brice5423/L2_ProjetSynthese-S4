#include "../include/heap.h"

/**********************************************************************************
 * ARRAY HEAP
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
    assert(AH);
    assert(getAHActualSize(AH));

    int nbElem;
    int posFg;
    int posFd;
    int fgExiste;
    int fdExiste;

    void *dataPos;
    void *dataPosFg;
    void *dataPosFd;
    void *dataSave;

    nbElem = getAHActualSize(AH);
    posFg = 2 * pos + 1;
    posFd = 2 * pos + 2;
    dataPos = getAHNodeAt(AH, pos);
    dataPosFg = getAHNodeAt(AH, posFg);

    fgExiste = (posFg < nbElem) ? 1 : 0;
    fdExiste = (posFd < nbElem) ? 1 : 0;
    dataPosFd = (fdExiste) ? getAHNodeAt(AH, posFd) : NULL;

    if (fgExiste) {
        if (fdExiste) {
            if (AH->preceed(dataPosFg, dataPos) && (AH->preceed(dataPosFg, dataPosFd) != 0)) {
                dataSave = dataPosFg;
                setAHNodeAt(AH, posFg, dataPos);
                setAHNodeAt(AH, pos, dataSave);

                if ((2 * posFg + 1) < nbElem) {
                    updateArrayHeapDownwards(AH, posFg);
                }

            } else if (AH->preceed(dataPosFd, dataPos)) {
                dataSave = dataPosFd;
                setAHNodeAt(AH, posFd, dataPos);
                setAHNodeAt(AH, pos, dataSave);

                if ((2 * posFd + 1) < nbElem) {
                    updateArrayHeapDownwards(AH, posFd);
                }
            }

        } else {
            if (AH->preceed(dataPosFg, dataPos)) {
                dataSave = dataPosFg;
                setAHNodeAt(AH, posFg, dataPos);
                setAHNodeAt(AH, pos, dataSave);
            }
        }
    }

    if (pos > 0) {
        int posPere;

        posPere = ((pos - 1) / 2);
        updateArrayHeapDownwards(AH, posPere);
    }
}

/**
 * On appel updateArrayHeapDownwards de telle sorte qu'il puisse ce lancer partout pour que \p AH soit un tas complet.\n
 * On appel updateArrayHeapDownwards à tout les node se trouvent à la hauteur \p hauteur.\n
 * \p hauteur est la dernier hauteur qui contient des node avec fils;
 *
 * @param[in] AH
 * @param[in] nbElem
 */
static void organiseTableauEnTas(ArrayHeap *AH) {
    int hauteur; // hauteur de l'"arbre" si on garde que les couches pleines
    int nbElemHauteur;
    int nbElemHauteurMoinsUnARacine;
    int i;

    hauteur = floor((log2(getAHActualSize(AH))));
    nbElemHauteur = (int) pow(2, hauteur - 1);
    nbElemHauteurMoinsUnARacine = nbElemHauteur - 1;

    for (i = 0; i < nbElemHauteur; i++) {
        updateArrayHeapDownwards(AH, nbElemHauteurMoinsUnARacine + i);
    }
}

ArrayHeap *ArrayToArrayHeap(void **A, int N,
                            int (*preceed)(const void *, const void *),
                            void (*viewHeapData)(const void *),
                            void (*freeHeapData)(void *)) {
    assert(A);
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    ArrayHeap *AH;

    AH = (ArrayHeap *) calloc(1, sizeof(ArrayHeap));
    assert(AH);

    // Donne les différents attributs de l'ArrayHeap AH
    AH->A = A;
    AH->MAX = N;
    AH->N = N;
    AH->preceed = preceed;
    AH->viewHeapData = viewHeapData;
    AH->freeHeapData = freeHeapData;

    // Organise le tableau pour qu'il soit un tas complet
    organiseTableauEnTas(AH);

    return AH;
}

void viewArrayHeap(const ArrayHeap *AH) {
    assert(AH);

    printf("[ ");
    for (int i = 0; i < getAHActualSize(AH); i++) {
        AH->viewHeapData(getAHNodeAt(AH, i));
        if ((i + 1) < getAHActualSize(AH)) {
            printf("; ");
        }
    }
    printf(" ]\n");
}

void freeArrayHeap(ArrayHeap *AH, int deletedata) {
    assert(AH);

    if (deletedata == 1) {
        for (int i = 0; i < getAHActualSize(AH); i++) {
            AH->freeHeapData(getAHNodeAt(AH, i));
        }
    }

    free(AH->A);
    AH->MAX = 0;
    AH->N = 0;
    AH->preceed = NULL;
    AH->viewHeapData = NULL;
    AH->freeHeapData = NULL;

    free(AH);
    AH = NULL;
}

void *ArrayHeapExtractMin(ArrayHeap *AH) {
    assert(AH);
    assert(getAHActualSize(AH));

    int posDernierData;
    void *dataRoot;

    posDernierData = getAHActualSize(AH) - 1;

    dataRoot = getAHNodeAt(AH, 0);
    setAHNodeAt(AH, 0, getAHNodeAt(AH, posDernierData));
    setAHNodeAt(AH, posDernierData, NULL);
    decreaseAHActualSize(AH);

    organiseTableauEnTas(AH);

    return dataRoot;
}

/**********************************************************************************
 * COMPLETE BINARY TREE HEAP
 **********************************************************************************/

CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
                    void (*viewHeapData)(const void *),
                    void (*freeHeapData)(void *)) {
    assert(preceed);
    assert(viewHeapData);
    assert(freeHeapData);

    CBTHeap *H;

    H = (CBTHeap *) calloc(1, sizeof(CBTHeap));
    assert(H);

    H->T = newCBTree(viewHeapData, freeHeapData);
    H->preceed = preceed;
    H->viewHeapData = viewHeapData;
    H->freeHeapData = freeHeapData;

    return H;
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
 * à corriger qui se trouve dans la position \p pos
 * (de la même façon que dans insertAfterLastTNode).\n
 * En remontant, on corrige en échangeant avec le père, si besoin.
 *
 * @param[in] node
 * @param[in] position
 * @param[in] preceed
 */
static void updateCBTHeapUpwards(TNode *node, int pos, int (*preceed)(const void *, const void *)) {
    assert(node);
    assert(pos); // peut pas être = 0
    assert(preceed);

    TNode *nodeFg;
    TNode *nodeFd;

    void *dataNode;
    void *dataFg;
    void *dataFd;

    nodeFg = Left(node);
    nodeFd = Right(node);

    dataNode = getTNodeData(node);
    dataFg = (nodeFg) ? getTNodeData(nodeFg) : NULL;
    dataFd = (nodeFd) ? getTNodeData(nodeFd) : NULL;

    if (pos == 1) {
        // dans le fils gauche
        if (preceed(dataFg, dataNode)) {
            CBTreeSwapData(nodeFg, node);
        }

    } else if (pos == 2) {
        // dans le fils droit
        if (preceed(dataFd, dataNode)) {
            CBTreeSwapData(nodeFd, node);
        }

    } else {
        // dans le cas pour l'appel récursive
        int nbNode;
        int h;
        double k;
        double t;

        nbNode = pos + 1;
        h = floor((log2(nbNode) + 1));
        k = nbNode - (pow(2, (h - 1)) - 1);
        t = (pow(2, (h - 1)) / 2);

        if (k <= t) {
            // A gauche de la node
            updateCBTHeapUpwards(Left(node), (nbNode - pow(2, h - 2) - 1), preceed);

            if (preceed(dataFg, dataNode)) {
                CBTreeSwapData(nodeFg, node);
            }

        } else {
            // A droite de la node
            updateCBTHeapUpwards(Right(node), (nbNode - pow(2, h - 1) - 1), preceed);

            if (preceed(dataFd, dataNode)) {
                CBTreeSwapData(nodeFd, node);
            }
        }
    }
}

void CBTHeapInsert(CBTHeap *H, void *data) {
    assert(H);

    CBTree *T;

    T = getCBTree(H);

    CBTreeInsert(T, data);
    if (getCBTreeSize(T) > 1) {
        updateCBTHeapUpwards(Root(T), (getCBTreeSize(T) - 1), H->preceed);
    }
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
    assert(node);
    assert(preceed);

    if (Left(node)) {
        TNode *nodeFg;
        TNode *nodeFd;

        int fdExiste;
        void *dataNode;
        void *dataFg;
        void *dataFd;

        nodeFg = Left(node);
        nodeFd = Right(node);

        fdExiste = (nodeFd) ? 1 : 0;
        dataNode = getTNodeData(node);
        dataFg = getTNodeData(nodeFg);
        dataFd = (fdExiste) ? getTNodeData(nodeFd) : NULL;

        if (fdExiste) {
            if (preceed(dataFg, dataNode) && preceed(dataFg, dataFd)) {
                // dans le cas où le fils gauche à la priorité sur le fils droit et le père
                CBTreeSwapData(nodeFg, node);
                updateCBTHeapDownwards(nodeFg, preceed);

            } else if (preceed(dataFd, dataNode)) {
                // dans le cas où le fils droit à la priorité sur le fils gauche et le père
                CBTreeSwapData(nodeFd, node);
                updateCBTHeapDownwards(nodeFd, preceed);
            }

        } else {
            if (preceed(dataFg, dataNode)) {
                // dans le cas où le fils gauche à la priorité sur le père
                CBTreeSwapData(nodeFg, node);
            }
        }
    }
}

void *CBTHeapExtractMin(CBTHeap *H) {
    assert(H);

    CBTree *T;
    TNode *root;
    void *data;
    int tailleArbre;

    T = getCBTree(H);
    root = Root(T);
    tailleArbre = getCBTreeSize(T);

    assert(T);

    if (tailleArbre > 0) {
        assert(root);

        if (tailleArbre > 1) {
            CBTreeSwapData(root, CBTreeGetLast(T));
            data = CBTreeRemove(T);
            updateCBTHeapDownwards(root, H->preceed);

        } else {
            data = CBTreeRemove(T);
        }

        return data;

    } else {
        return NULL;
    }
}

void viewCBTHeap(const CBTHeap *H) {
    assert(H);
    viewCBTree(getCBTree(H), 2);
}

void freeCBTHeap(CBTHeap *H, int deletenode) {
    assert(H);

    freeCBTree(getCBTree(H), deletenode);
    H->preceed = NULL;
    H->viewHeapData = NULL;
    H->freeHeapData = NULL;

    free(H);
    H = NULL;
}

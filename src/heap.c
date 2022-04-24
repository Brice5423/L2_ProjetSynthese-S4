#include "../include/heap.h"

/**********************************************************************************
 * ARRAY HEAP TODO BriceBriçou : liste de tas ======================================   à tester
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
    nbElemHauteur = pow(2, hauteur - 1);
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
    AH->A = (void **) calloc(N, sizeof(void *));
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
    // TODO freeArrayHeap : à tester -----------------------------------
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
}

void *ArrayHeapExtractMin(ArrayHeap *AH) {
    // TODO ArrayHeapExtractMin : à tester ----------------------------
    // TODO (à voir si c'est ce qu'il demande de faire)
    assert(AH);
    assert(getAHActualSize(AH));

    int posDernierData;
    void *dataRoot;

    posDernierData = getAHActualSize(AH) - 1;

    dataRoot = getAHNodeAt(AH, 0);
    setAHNodeAt(AH, 0, getAHNodeAt(AH, posDernierData));
    setAHNodeAt(AH, posDernierData, NULL);
    decreaseAHActualSize(AH);

    updateArrayHeapDownwards(AH, posDernierData - 2);

    return dataRoot;
}

/**********************************************************************************
 * COMPLETE BINARY TREE HEAP TODO BriceBriçou : Arbre binaire complet de tas ==============
 **********************************************************************************/

CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
                    void (*viewHeapData)(const void *),
                    void (*freeHeapData)(void *)) {
    // TODO newCBTHeap : à tester ------------------------------------
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
    // TODO getCBTree : à tester ----------------------------------------
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
    // TODO updateCBTHeapUpwards : à tester
    assert(node);
    assert(pos); // peut pas être = 0
    assert(preceed);

    if (pos == 1) {
        // dans le fils gauche
        TNode *nodeFg;

        nodeFg = Left(node);

        if (preceed(node, nodeFg)) {
            CBTreeSwapData(nodeFg, node);
        }

    } else if (pos == 2) {
        // dans le fils droit
        TNode *nodeFd;

        nodeFd = Right(node);

        if (preceed(node, nodeFd)) {
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
        } else {
            // A droite de la node
            updateCBTHeapUpwards(Right(node), (nbNode - pow(2, h - 1) - 1), preceed);
        }
    }
}

void CBTHeapInsert(CBTHeap *H, void *data) {
    // TODO CBTHeapInsert : à tester -----------------------------------
    assert(H);

    CBTree *T;

    T = getCBTree(H);

    CBTreeInsert(T, data);
    if (getCBTreeSize(T) > 1) {
        updateCBTHeapUpwards(Root(T), getCBTreeSize(T), H->preceed);
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
    // TODO updateCBTHeapDownwards : à tester
    assert(node);
    assert(preceed);

    if (Left(node) != NULL) {
        TNode *nodeFg;
        TNode *nodeFd;
        int fdExiste;
        void *dataNode;
        void *dataFg;
        void *dataFd;

        nodeFg = Left(node);
        nodeFd = Right(node);
        fdExiste = (nodeFd != NULL) ? 1 : 0;
        dataNode = getTNodeData(node);
        dataFg = getTNodeData(nodeFg);
        dataFd = (fdExiste) ? getTNodeData(nodeFd) : NULL;

        if (preceed(dataFg, dataNode) && (!fdExiste || (fdExiste && preceed(dataFg, dataFd)))) {
            // dans le cas où le fils gauche à la priorité sur le fils droit et le père
            CBTreeSwapData(nodeFg, node);
            updateCBTHeapDownwards(nodeFg, preceed);

        } else if (fdExiste && preceed(dataFd, dataNode)) {
            // dans le cas où le fils droit à la priorité sur le fils gauche et le père
            CBTreeSwapData(nodeFd, node);
            updateCBTHeapDownwards(nodeFd, preceed);
        }
    }
}

void *CBTHeapExtractMin(CBTHeap *H) {
    // TODO CBTHeapExtractMin : à tester ------------------------------
    assert(H);

    CBTree *T;
    TNode *root;
    void *dataRoot;
    int tailleArbre;

    T = getCBTree(H);
    root = Root(T);
    tailleArbre = getCBTreeSize(T);

    assert(root);
    assert(tailleArbre);

    if (tailleArbre > 1) {
        CBTreeSwapData(root, CBTreeGetLast(T));
        updateCBTHeapDownwards(root, H->preceed);
    }
    dataRoot = CBTreeRemove(T);

    return dataRoot;
}

void viewCBTHeap(const CBTHeap *H) {
    // TODO viewCBTHeap : à tester ------------------------------------
    assert(H);

    viewCBTree(getCBTree(H), 2);
}

void freeCBTHeap(CBTHeap *H, int deletenode) {
    // TODO freeCBTHeap : à tester -------------------------------------
    assert(H);

    freeCBTree(getCBTree(H), deletenode);
    H->preceed = NULL;
    H->viewHeapData = NULL;
    H->freeHeapData = NULL;

    free(H);
}
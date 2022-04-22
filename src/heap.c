#include "../include/heap.h"

/**********************************************************************************
 * ARRAY HEAP TODO BriceBriçou : liste de tas ======================================   à tester
 **********************************************************************************/

int getAHMaxSize(const ArrayHeap *AH) {
    // TODO getAHMaxSize : à tester
    assert(AH);
    return AH->MAX;
}

int getAHActualSize(const ArrayHeap *AH) {
    // TODO getAHActualSize : à tester
    assert(AH);
    return AH->N;
}

void *getAHNodeAt(const ArrayHeap *AH, int pos) {
    // TODO getAHNodeAt : à tester
    assert(AH);
    return AH->A[pos];
}

void decreaseAHActualSize(ArrayHeap *AH) {
    // TODO decreaseAHActualSize : à tester
    assert(AH);
    AH->N--;
}

void setAHNodeAt(ArrayHeap *AH, int position, void *newData) {
    // TODO setAHNodeAt : à tester
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

    if (pos) {
        int posFg;
        int posFd;
        int fdExiste;
        void *dataPos;
        void *dataPosFg;
        void *dataPosFd;
        void *dataSave;

        posFg = 2 * pos + 1;
        posFd = 2 * pos + 2;
        dataPos = getAHNodeAt(AH, pos);
        dataPosFg = getAHNodeAt(AH, posFg);

        fdExiste = (posFd < getAHActualSize(AH)) ? 1 : 0;
        dataPosFd = (fdExiste) ? getAHNodeAt(AH, posFd) : NULL;

        if (AH->preceed(dataPosFg, dataPos) && (!fdExiste || (fdExiste && AH->preceed(dataPosFg, dataPosFd)))) {
            dataSave = dataPosFg;
            setAHNodeAt(AH, posFg, dataPos);
            setAHNodeAt(AH, pos, dataSave);

        } else if (fdExiste && AH->preceed(dataPosFd, dataPos)) {
            dataSave = dataPosFd;
            setAHNodeAt(AH, posFd, dataPos);
            setAHNodeAt(AH, pos, dataSave);
        }

    } else {
        updateArrayHeapDownwards(AH, pos--);
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

    int i;
    ArrayHeap *AH;

    AH = (ArrayHeap *) calloc(1, sizeof(ArrayHeap));
    assert(AH);

    // Donne les différents attributs de l'ArrayHeap AH
    AH->A = A;
    AH->MAX = 1048576; // = 2^20 TODO AH->MAX = ?
    AH->N = N;
    AH->preceed = preceed;
    AH->viewHeapData = viewHeapData;
    AH->freeHeapData = freeHeapData;

    // Organise les datas de l'array on fonction du preceed
    // de 0 à N - 2 (-1 car taille 1 + grand et -1 car inutile sur dernier élément
    for (i = 0; i < (N - 1); i++) {
        updateArrayHeapDownwards(AH, (N - 1 - i));
    }

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
    // TODO newCBTHeap : à tester
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
    // TODO getCBTree : à tester
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
    // TODO updateCBTHeapUpwards : à tester
    assert(node);
    assert(pos); // peut pas être = 0
    assert(preceed);

    if (pos == 1) {
        // dans le fils gauche
        TNode *nodeFg;
        void *dataFgSave;

        nodeFg = Left(node);

        if (preceed(node, nodeFg)) {
            dataFgSave = getTNodeData(nodeFg);
            setTNodeData(nodeFg, getTNodeData(node));
            setTNodeData(node, dataFgSave);
        }

    } else if (pos == 2) {
        // dans le fils droit
        TNode *nodeFd;
        void *dataFgSave;

        nodeFd = Right(node);

        if (preceed(node, nodeFd)) {
            dataFgSave = getTNodeData(nodeFd);
            setTNodeData(nodeFd, getTNodeData(node));
            setTNodeData(node, dataFgSave);
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
    // TODO CBTHeapInsert : à tester
    assert(H);

    CBTree *T;

    T = getCBTree(H);

    CBTreeInsert(T, data);
    updateCBTHeapUpwards(Root(T), getCBTreeSize(T), H->preceed);
    increaseCBTreeSize(T);
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

    TNode *nodeFg;
    TNode *nodeFd;
    int fdExiste;
    void *dataSave;
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
        dataSave = dataFg;
        setTNodeData(nodeFg, dataNode);
        setTNodeData(node, dataSave);

    } else if (fdExiste && preceed(dataFd, dataNode)) {
        // dans le cas où le fils droit à la priorité sur le fils gauche et le père
        dataSave = dataFd;
        setTNodeData(nodeFd, dataNode);
        setTNodeData(node, dataSave);
    }

    // Appel recursive par le fils gauche
    if (Left(nodeFg) != NULL) {
        updateCBTHeapDownwards(nodeFg, preceed);
    }

    // Appel recursive par le fils droit
    if (fdExiste && Left(nodeFd) != NULL) {
        updateCBTHeapDownwards(nodeFd, preceed);
    }
}

void *CBTHeapExtractMin(CBTHeap *H) {
    // TODO CBTHeapExtractMin
    assert(H);

    CBTree *T;
    TNode *nodeRacine;
    void *dataPlusGrandePriorite;

    T = getCBTree(H);
    nodeRacine = Root(T);

    updateCBTHeapDownwards(nodeRacine, H->preceed);
    dataPlusGrandePriorite = getTNodeData(nodeRacine);

    // TODO On doit retirer le node mais comment faire ça -_-

    return dataPlusGrandePriorite;
}

void viewCBTHeap(const CBTHeap *H) {
    // TODO viewCBTHeap : à tester
    assert(H);

    viewCBTree(getCBTree(H), 2); // TODO je ne suis pas sur qu'il faut que faire ça -_-
}

void freeCBTHeap(CBTHeap *H, int deletenode) {
    // TODO freeCBTHeap : à tester
    assert(H);

    freeCBTree(getCBTree(H), deletenode);
    H->preceed = NULL;
    H->viewHeapData = NULL;
    H->freeHeapData = NULL;
    free(H);
}
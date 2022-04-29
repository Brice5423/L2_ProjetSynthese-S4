#include "../include/tree.h"

/********************************************************************
 * TNode
 ********************************************************************/
//TODO : commenter
TNode *newTNode(void *data) {
    assert(data);

    TNode *node;

    node = (TNode *) calloc(1, sizeof(TNode));
    assert(node);

    node->data = data;
    setRight(node, NULL);
    setLeft(node, NULL);

    return node;
}

void *getTNodeData(const TNode *node) {
    assert(node);
    return node->data;
}

TNode *Left(const TNode *node) {
    return node->left;
}

TNode *Right(const TNode *node) {
    return node->right;
}

void setTNodeData(TNode *node, void *newData) {
    assert(node);
    node->data = newData;
}

void setLeft(TNode *node, TNode *newLeft) {
    node->left = newLeft;
}

void setRight(TNode *node, TNode *newRight) {
    node->right = newRight;
}

/********************************************************************
 * Complete Binary Tree
 ********************************************************************/

CBTree *newCBTree(void (*viewData)(const void *), void (*freeData)(void *)) {
    CBTree *T;

    T = (CBTree *) calloc(1, sizeof(CBTree));
    assert(T);

    T->root = NULL;
    resetCBTreeSize(T);
    T->viewData = viewData;
    T->freeData = freeData;

    return T;
}

int treeIsEmpty(CBTree *T) {
    assert(T);
    return ((int) (getCBTreeSize(T) == 0));
}

int getCBTreeSize(const CBTree *T) {
    assert(T);
    return T->numelm;
}

TNode *Root(const CBTree *T) {
    assert(T);
    return T->root;
}

void increaseCBTreeSize(CBTree *T) {
    assert(T);
    T->numelm++;
}

void decreaseCBTreeSize(CBTree *T) {
    assert(T);
    T->numelm--;
}

void resetCBTreeSize(CBTree *T) {
    assert(T);
    T->numelm = 0;
}

void setRoot(CBTree *T, TNode *newRoot) {
    assert(T);

    if (newRoot) {
        TNode *root;

        root = Root(T);

        if (root != NULL) {
            setLeft(newRoot, Left(root));
            setRight(newRoot, Right(root));

            (*T->freeData)(getTNodeData(root));
            setLeft(root, NULL);
            setRight(root, NULL);

            free(root);
            root = NULL;
        }
    }

    T->root = newRoot;
}

/**
 * @brief Libère récursivement le sous-arbre raciné au nœud \p node.
 * Dans le cas où le pointeur de fonction \p freeData n'est pas NULL,
 * la mémoire de la donnée du nœud actuel est aussi libérée.\n
 * NB : procédure récursive.
 *
 * @param[in] node
 * @param[in] freeData
 */
static void freeTNode(TNode *node, void (*freeData)(void *)) {
    assert(node);

    if (Left(node)) {
        freeTNode(Left(node), freeData);
    }

    if (Right(node)) {
        freeTNode(Right(node), freeData);
    }

    setLeft(node, NULL);
    setRight(node, NULL);
    if (freeData) {
        (*freeData)(getTNodeData(node));
    }

    free(node);
    node = NULL;
}

/**
 * NB : Utilisez la procédure récursive freeTNode.\n
 * Vous devez initialiser le paramètre freeData par rapport à la valeur de deleteData.
 * @param deleteData 1 : data free & 0 : data non free
 */
void freeCBTree(CBTree *T, int deleteData) {
    // TODO freeCBTree : voir comment corrigé son problème de mémoire
    assert(T);

    if (Root(T)) {
        if (deleteData == 1) {
            freeTNode(Root(T), T->freeData);
        } else {
            freeTNode(Root(T), NULL);
        }
    }

    T->root = NULL;
    resetCBTreeSize(T);
    T->viewData = NULL;
    T->freeData = NULL;

    free(T);
    T = NULL;
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours préfixé.\n
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void preorder(TNode *node, void (*viewData)(const void *)) {
    assert(node);
    assert(viewData);

    (*viewData)(getTNodeData(node));

    if (Left(node)) {
        printf("-");
        preorder(Left(node), viewData);
    }

    if (Right(node)) {
        printf("-");
        preorder(Right(node), viewData);
    }
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours infixé.\n
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void inorder(TNode *node, void (*viewData)(const void *)) {
    assert(node);
    assert(viewData);

    if (Left(node)) {
        inorder(Left(node), viewData);
        printf("-");
    }

    (*viewData)(getTNodeData(node));

    if (Right(node)) {
        printf("-");
        inorder(Right(node), viewData);
    }
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours postfixé.\n
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void postorder(TNode *node, void (*viewData)(const void *)) {
    assert(node);
    assert(viewData);

    if (Left(node)) {
        postorder(Left(node), viewData);
        printf("-");
    }

    if (Right(node)) {
        postorder(Right(node), viewData);
        printf("-");
    }

    (*viewData)(getTNodeData(node));
}

/**
 * NB : Utilisez les procédures récursives preorder, inorder et postorder.
 * Rappel : order = 0 (preorder), 1 (postorder), 2 (inorder)
 */
void viewCBTree(const CBTree *T, int order) {
    assert(T);

    if (Root(T)) {
        if (order == 0) {
            preorder(Root(T), T->viewData);

        } else if (order == 1) {
            postorder(Root(T), T->viewData);

        } else {
            inorder(Root(T), T->viewData);
        }

    } else {
        printf("--- L'arbre est vide ---");
    }

    printf("\n");
}

/**
 * @brief Insère récursivement un nouveau nœud de donnée \p data
 * dans l'arbre raciné au nœud \p node.\n
 * La position (par rapport à la racine \p node) où le nouveau nœud
 * va être insérer est indiquée par le paramètre \p position.\n
 * (voir la figure ci-dessous pour la définition de la position)\n
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 *
 * @param[in] node La racine de l'arbre actuel.
 * @param[in] position La position du nouveau élément par rapport à la racine \p node.
 * @param[in] data La donnée à insérer.
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *insertAfterLastTNode(TNode *node, int position, void *data) {
    assert(node);

    if (position == 0) {
        return newTNode(data);

    } else if (position == 1) {
        setLeft(node, newTNode(data));
        return node;

    } else if (position == 2) {
        setRight(node, newTNode(data));
        return node;

    } else {
        int nbNode;
        int h;
        double k;
        double t;

        nbNode = position + 1;
        h = floor((log2(nbNode) + 1));
        k = nbNode - (pow(2, (h - 1)) - 1);
        t = (pow(2, (h - 1)) / 2);

        if (k <= t) {
            // A gauche de la node
            setLeft(node, insertAfterLastTNode(Left(node), (nbNode - pow(2, h - 2) - 1), data));
        } else {
            // A droite de la node
            setRight(node, insertAfterLastTNode(Right(node), (nbNode - pow(2, h - 1) - 1), data));
        }

        return node;
    }
}

/**
 * NB : Utilisez la procédure récursive insertAfterLastTNode a fin de lancer l'insertion.
 */
void CBTreeInsert(CBTree *T, void *data) {
    assert(T);

    if (getCBTreeSize(T) == 0) {
        setRoot(T, newTNode(data));
    } else {
        insertAfterLastTNode(Root(T), getCBTreeSize(T), data);
    }

    increaseCBTreeSize(T);
}

/**
 * @brief Supprime récursivement le dernier nœud de l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) du nœud à supprimer
 * est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
 * La mémoire du dernier nœud est libérée mais pas la mémoire de sa donnée.
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 * \n
 * Cette fonction fait aucune suppression.\n
 * Elle renvoie la node qui contient la modification.\n
 * La node à sup est free mais ça \p data devra être free dans la fonction qui appel removeLastTNode\n.
 * Le paramètre \p data contient la donnée que la node doit sup.
 *
 * @param[in] node La racine de l'arbre actuel.
 * @param[in] position La position de l'élément à supprimer par rapport à la racine \p node.
 * @param[out] data La donnée du nœud supprimé (sortie).
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *removeLastTNode(TNode *node, int position, void **data) {
    assert(node);

    if (position == 0) {
        *data = getTNodeData(node);

        free(node);
        node = NULL;

        return NULL;

    } else {
        int nbNode;
        int h;
        double k;
        double t;

        nbNode = position + 1;
        h = floor((log2(nbNode) + 1));
        k = nbNode - (pow(2, (h - 1)) - 1);
        t = (pow(2, (h - 1)) / 2);

        if (k <= t) {
            // A gauche de la node
            setLeft(node, removeLastTNode(Left(node), (nbNode - pow(2, h - 2) - 1), data));
        } else {
            // A droite de la node
            setRight(node, removeLastTNode(Right(node), (nbNode - pow(2, h - 1) - 1), data));
        }

        return node;
    }
}

/**
 * NB : Utilisez la procédure récursive removeLastTNode a fin de lancer la suppression.
 */
void *CBTreeRemove(CBTree *T) {
    assert(T);

    void *data;

    removeLastTNode(Root(T), (getCBTreeSize(T) - 1), &data);
    decreaseCBTreeSize(T);

    if (!getCBTreeSize(T)) {
        setRoot(T, NULL);
    }

    return data;
}

/**
 * @brief Restitue récursivement le dernier nœud de l'arbre raciné au nœud \p node.\n
 * La position (par rapport à la racine \p node) de ce dernier nœud
 * est indiquée par le paramètre \p position\n
 * (voir la figure ci-dessous pour la définition de la position).\n
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 *
 * @param node La racine de l'arbre actuel.
 * @param position La position du dernier nœud par rapport à la racine \p node.
 * @return TNode* Le dernier nœud de l'arbre.
 */
static TNode *getLastTNode(TNode *node, int position) {
    assert(node);

    if (position == 0) {
        return node;

    } else {
        int nbNode;
        int h;
        double k;
        double t;

        nbNode = position + 1;
        h = floor((log2(nbNode) + 1));
        k = nbNode - (pow(2, (h - 1)) - 1);
        t = (pow(2, (h - 1)) / 2);

        if (k <= t) {
            // A gauche de la node
            return getLastTNode(Left(node), ((int) (nbNode - pow(2, h - 2) - 1)));
        } else {
            // A droite de la node
            return getLastTNode(Right(node), ((int) (nbNode - pow(2, h - 1) - 1)));
        }
    }
}

/**
 * NB : Utilisez la procédure récursive getLastTNode à fin de lancer la recherche.
 */
TNode *CBTreeGetLast(CBTree *T) {
    assert(T);

    int tailleArbre;

    tailleArbre = getCBTreeSize(T);

    if (tailleArbre) {
        return getLastTNode(Root(T), (getCBTreeSize(T) - 1));

    } else {
        return NULL;
    }
}

/**
 * Echange les data des deux nodes entre eux.
 *
 * @param node1
 * @param node2
 */
void CBTreeSwapData(TNode *node1, TNode *node2) {
    void *data1;

    data1 = getTNodeData(node1);
    setTNodeData(node1, getTNodeData(node2));
    setTNodeData(node2, data1);
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "../include/tree.h"
#include "../include/util.h"

/********************************************************************
 * TNode
 ********************************************************************/

TNode *newTNode(void *data) {
    assert(data);

    TNode *node;

    node = (TNode *) calloc(1, sizeof(TNode));
    assert(node);

    node->data = data;

    return node;
}

void *getTNodeData(const TNode *node) {
    return node->data;
}

TNode *Left(const TNode *node) {
    return node->left;
}

TNode *Right(const TNode *node) {
    return node->right;
}

void setTNodeData(TNode *node, void *newData) {
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
    // TODO newCBTree : à tester
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
    // TODO treeIsEmpty : à tester
    assert(T);

    return ((int) (getCBTreeSize(T) == 0));
}

int getCBTreeSize(const CBTree *T) {
    // TODO getCBTreeSize : à tester
    return T->numelm;
}

TNode *Root(const CBTree *T) {
    // TODO Root : à tester
    return T->root;
}

void increaseCBTreeSize(CBTree *T) {
    // TODO increaseCBTreeSize : à tester
    T->numelm++;
}

void decreaseCBTreeSize(CBTree *T) {
    // TODO decreaseCBTreeSize : à tester
    T->numelm--;
}

void resetCBTreeSize(CBTree *T) {
    // TODO resetCBTreeSize : à tester
    T->numelm = 0;
}

void setRoot(CBTree *T, TNode *newRoot) {
    // TODO setRoot : à tester
    assert(T);
    assert(newRoot);

    TNode *root;

    root = Root(T);

    setLeft(newRoot, Left(root));
    setRight(newRoot, Right(root));

    (*T->freeData)(root);

    T->root = newRoot;
}

/**
 * @brief Libère récursivement le sous-arbre raciné au nœud \p node.
 * Dans le cas où le pointeur de fonction \p freeData n'est pas NULL,
 * la mémoire de la donnée du nœud actuel est aussi libérée.
 * NB : procédure récursive.
 * 
 * @param[in] node 
 * @param[in] freeData 
 */
static void freeTNode(TNode *node, void (*freeData)(void *)) {
    // TODO freeTNode : à tester
    if ((Left(node) != NULL) && (Right(node) != NULL)) {
        freeTNode(Left(node), freeData);
        freeTNode(Right(node), freeData);

    } else if (Left(node) != NULL) {
        freeTNode(Left(node), freeData);

    } else if (Right(node) != NULL) {
        freeTNode(Right(node), freeData);
    }

    (*freeData)(node);
}

/**
 * NB : Utilisez la procédure récursive freeTNode.
 * Vous devez initialiser le paramètre freeData
 * par rapport à la valeur de deleteData.
 */
void freeCBTree(CBTree *T, int deleteData) {
    // TODO freeCBTree : à tester
    if (deleteData == 1) {
        freeTNode(Root(T), T->freeData);
    }

    resetCBTreeSize(T);
    free(T->viewData);
    T->viewData = NULL;
    free(T->freeData);
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
    // TODO preorder : à tester
    (*viewData)(node);

    if (Left(node) != NULL) {
        preorder(Left(node), viewData);
    }

    if (Right(node) != NULL) {
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
    // TODO inorder : à tester
    if (Left(node) != NULL) {
        preorder(Left(node), viewData);
    }

    (*viewData)(node);

    if (Right(node) != NULL) {
        preorder(Right(node), viewData);
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
    // TODO postorder : à tester
    if (Left(node) != NULL) {
        preorder(Left(node), viewData);
    }

    if (Right(node) != NULL) {
        preorder(Right(node), viewData);
    }

    (*viewData)(node);
}

/**
 * NB : Utilisez les procédures récursives preorder, inorder et postorder.
 * Rappel : order = 0 (preorder), 1 (postorder), 2 (inorder)
 */
void viewCBTree(const CBTree *T, int order) {
    // TODO viewCBTree : à tester
    if (order == 0) {
        preorder(Root(T), T->viewData);

    } else if (order == 1) {
        postorder(Root(T), T->viewData);

    } else if (order == 2) {
        inorder(Root(T), T->viewData);
    }
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
    // TODO insertAfterLastTNode : à tester
    if (position == 0) {
        return newTNode(data);

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
 * NB : Utilisez la procédure récursive insertAfterLastTNode afin de lancer l'insertion.
 */
void CBTreeInsert(CBTree *T, void *data) {
    // TODO CBTreeInsert : à tester
    assert(Root(T));

    insertAfterLastTNode(Root(T), getCBTreeSize(T), data);
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
    // TODO removeLastTNode : à test
    if (position == 0) {
        data = &getTNodeData(node);
        free(node);

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
            setLeft(node, insertAfterLastTNode(Left(node), (nbNode - pow(2, h - 2) - 1), data));
        } else {
            // A droite de la node
            setRight(node, insertAfterLastTNode(Right(node), (nbNode - pow(2, h - 1) - 1), data));
        }

        return node
    }
}

/**
 * NB : Utilisez la procédure récursive removeLastTNode afin de lancer la suppression.
 */
void *CBTreeRemove(CBTree *T) {
    // TODO CBTreeRemove : à tester
    assert(Root(T));

    removeLastTNode(Root(T), getCBTreeSize(T), data);
    decreaseCBTreeSize(T);
    (*T->freeData)(**data);
    free(*data);
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
    // TODO getLastTNode : à tester
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
            return getLastTNode(Left(node), (nbNode - pow(2, h - 2) - 1));
        } else {
            // A droite de la node
            return getLastTNode(Right(node), (nbNode - pow(2, h - 1) - 1));
        }
    }
}

/**
 * NB : Utilisez la procédure récursive getLastTNode afin de lancer la recherche.
 */
TNode *CBTreeGetLast(CBTree *T) {
    // TODO CBTreeGetLast : à tester
    assert(T);

    return getLastTNode(Root(T), getCBTreeSize(T));
}

/**
 * Echange les data des deux nodes entre eux.
 *
 * @param node1
 * @param node2
 */
void CBTreeSwapData(TNode *node1, TNode *node2) {
    // TODO CBTreeSwapData : à tester
    void *data1;

    data1 = getTNodeData(node1);
    setTNodeData(node1, getTNodeData(node2));
    setTNodeData(node2, data1);
}

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
    TNode *TNode = (struct TNode *) calloc(1, sizeof(struct TreeNode));
    assert(TNode);
    TNode->data = data;
    return TNode;
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
    // TODO newCBTree
}

int treeIsEmpty(CBTree *T) {
    // TODO treeIsEmpty
}

int getCBTreeSize(const CBTree *T) {
    // TODO getCBTreeSize
}

TNode *Root(const CBTree *T) {
    // TODO Root
}

void increaseCBTreeSize(CBTree *T) {
    // TODO increaseCBTreeSize
}

void decreaseCBTreeSize(CBTree *T) {
    // TODO decreaseCBTreeSize
}

void resetCBTreeSize(CBTree *T) {
    // TODO resetCBTreeSize
}

void setRoot(CBTree *T, TNode *newRoot) {
    // TODO setRoot
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
    // TODO freeTNode : Faire des tests
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
    // TODO freeCBTree
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours préfixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 * 
 * @param[in] node 
 * @param[in] viewData 
 */
static void preorder(TNode *node, void (*viewData)(const void *)) {
    // TODO preorder
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours infixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 * 
 * @param[in] node 
 * @param[in] viewData 
 */
static void inorder(TNode *node, void (*viewData)(const void *)) {
    // TODO inorder
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours postfixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 * 
 * @param[in] node 
 * @param[in] viewData 
 */
static void postorder(TNode *node, void (*viewData)(const void *)) {
    // TODO postorder
}

/**
 * NB : Utilisez les procédures récursives preorder, inorder et postorder.
 * Rappel : order = 0 (preorder), 1 (postorder), 2 (inorder)
 */
void viewCBTree(const CBTree *T, int order) {
    // TODO viewCBTree
}

/**
 * @brief Insère récursivement un nouveau nœud de donnée \p data
 * dans l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) où le nouveau nœud
 * va être insérer est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
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
 * @param[in] position La position du nouveau élément
 * 						par rapport à la racine \p node.
 * @param[in] data La donnée à insérer.
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *insertAfterLastTNode(TNode *node, int position, void *data) {
    // TODO insertAfterLastTNode
}

/**
 * NB : Utilisez la procédure récursive insertAfterLastTNode
 * afin de lancer l'insertion.
 */
void CBTreeInsert(CBTree *T, void *data) {
    // TODO CBTreeInsert
}

/**
 * @brief Supprime récursivement le dernier nœud
 * de l'arbre raciné au nœud \p node.
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
 * 
 * @param[in] node La racine de l'arbre actuel.
 * @param[in] position La position de l'élément à supprimer
 *                         par rapport à la racine \p node.
 * @param[out] data La donnée du nœud supprimé (sortie).
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *removeLastTNode(TNode *node, int position, void **data) {
    // TODO removeLastTNode
}

/**
 * NB : Utilisez la procédure récursive removeLastTNode
 * afin de lancer la suppression.
 */
void *CBTreeRemove(CBTree *T) {
    assert(Root(T));
    // TODO CBTreeRemove
}

/**
 * @brief Restitue récursivement le dernier nœud
 * de l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) de ce dernier nœud
 * est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
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
    // TODO getLastTNode
}

/**
 * NB : Utilisez la procédure récursive getLastTNode
 * afin de lancer la recherche.
 */
TNode *CBTreeGetLast(CBTree *T) {
    // TODO CBTreeGetLast
}

void CBTreeSwapData(TNode *node1, TNode *node2) {
    // TODO CBTreeSwapData
}
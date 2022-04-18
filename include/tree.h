#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "util.h"

/**
 * @brief
 * Arbre binaire complet générique
 */

/**
 * @brief Un élément d'un arbre binaire contient :\n
 * (+) Une donnée (data),\n
 * (+) Une référence (left) au fils gauche,\n
 * (+) Une référence (right) au fils droit.
 */
typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TNode;

/**
 * @brief Construit et initialise un nouveau noeud d'un arbre binaire.
 * 
 * @param[in] data Donnée à affecter au nouveau nœud.
 * @return TNode* Le nouveau nœud créé.
 */
TNode *newTNode(void *data);

/**
 * @brief Restitue la donnée du nœud \p node.
 * 
 * @param[in] node 
 * @return void* 
 */
void *getTNodeData(const TNode *node);

/**
 * @brief Restitue le fils gauche du nœud \p node.
 * 
 * @param[in] node 
 * @return TNode* 
 */
TNode *Left(const TNode *node);

/**
 * @brief Restitue le fils droit du nœud \p node.
 * 
 * @param[in] node 
 * @return TNode* 
 */
TNode *Right(const TNode *node);

/**
 * @brief Remplace la donnée du nœud \p node par \p newData.
 * 
 * @param[in] node 
 * @param[in] newData 
 */
void setTNodeData(TNode *node, void *newData);

/**
 * @brief Remplace le fils gauche du nœud \p node par \p newLeft.
 * 
 * @param[in] node 
 * @param[in] newLeft 
 */
void setLeft(TNode *node, TNode *newLeft);

/**
 * @brief Remplace le fils gauche du nœud \p node par \p newRight.
 * 
 * @param[in] node 
 * @param[in] newRight 
 */
void setRight(TNode *node, TNode *newRight);

/**
 * @brief L'arbre binaire complet est une structure contenant :\n
 * (+) une référence (root) sur sa racine,\n
 * (+) le nombre d'éléments,\n
 * (+) un pointeur de fonction pour afficher ses données,\n
 * (+) un pointeur de fonction pour libérer la mémoire de ses données.\n
 */
typedef struct CompleteBinaryTree {
    TNode *root;
    int numelm;

    void (*viewData)(const void *);

    void (*freeData)(void *);
} CBTree;

/**
 * @brief Construit et initialise un arbre binaire complet vide.
 * 
 * Les deux pointeurs de fonction passés en paramètre indiquent
 * de façon implicite le type de la donnée de l'arbre créée.
 * 
 * @param[in] viewData Pointeur de fonction pour afficher les données
 * du nouveau arbre.
 * @param[in] freeData Pointeur de fonction pour libérer la mémoire
 * des données du nouveau arbre.
 * @return CBTree* Le nouveau arbre binaire complet créé.
 */
CBTree *newCBTree(void (*viewData)(const void *), void (*freeData)(void *));

/**
 * @brief Renvoie 1 si l'arbre \p T est vide, sinon renvoie 0.
 * 
 * @param[in] T 
 * @return int 
 */
int treeIsEmpty(CBTree *T);

/**
 * @brief Restitue la taille (nombre d'éléments) de l'arbre \p T.
 * 
 * @param[in] T 
 * @return int
 */
int getCBTreeSize(const CBTree *T);

/**
 * @brief Restitue la racine de l'arbre \p T.
 * 
 * @param[in] T 
 * @return TNode* 
 */
TNode *Root(const CBTree *T);

/**
 * @brief Incrémente la taille de l'arbre \p T par 1.
 * 
 * @param[in] T 
 */
void increaseCBTreeSize(CBTree *T);

/**
 * @brief Décrémente la taille de l'arbre \p T par 1.
 * 
 * @param[in] T 
 */
void decreaseCBTreeSize(CBTree *T);

/**
 * @brief Réinitialise la taille de l'arbre \p T à zéro.
 * 
 * @param[in] T 
 */
void resetCBTreeSize(CBTree *T);

/**
 * @brief Remplace la racine de l'arbre \p T par \p newRoot.
 * 
 * @param[in] T 
 * @param[in] newRoot 
 */
void setRoot(CBTree *T, TNode *newRoot);

/**
 * @brief Deux possibilités pour liberer la memoire de l'arbre \p T :\n
 * (+) Si le paramètre \p deleteData vaut 0,
 *     alors les données (data) référencées par les éléments
 *     de l'arbre \p T ne sont pas supprimées;
 *     (Supprime l'arbre mais pas les éléments)\n
 * (+) Si le paramètre \p deleteData vaut 1,
 *     alors le pointeur de fonction freeData de la structure CBTree
 *     va servir à supprimer les données (data) référencées par
 *     les éléments de l'arbre \p T.
 *     (Supprime les éléments et l'arbre)
 * 
 * @param[in] T 
 * @param[in] deleteData 
 */
void freeCBTree(CBTree *T, int deleteData);

/**
 * @brief Affiche les éléments de l'arbre \p T.
 * Les données de chaque élément sont affichées grâce au pointeur
 * de fonction viewData de la structure CBTree.
 * 
 * @param[in] T 
 * @param[in] order Spécifie l'ordre d'affichage :\n
 * 					(+) 0 = ordre préfixe,\n
 * 					(+) 1 = ordre postfixe,\n
 * 					(+) 2 = ordre infixe.
 */
void viewCBTree(const CBTree *T, int order);

/**
 * @brief Insère au dernier niveau et le plus à gauche possible
 * dans l'arbre \p T un nouveau nœud de donnée \p data.
 * 
 * @param[in] T 
 * @param[in] data 
 */
void CBTreeInsert(CBTree *T, void *data);

/**
 * @brief Supprime le dernier nœud de l'arbre \p T et restitue sa donnée.
 * La mémoire du nœud supprimé est libérée mais pas la mémoire de la donnée.
 * 
 * NB : le dernier nœud d'un arbre binaire complet se trouve au dernier
 * niveau le plus à droite possible.
 * 
 * @param[in] T L'arbre ne doit pas être vide.
 * @return void* La donnée du nœud supprimé.
 */
void *CBTreeRemove(CBTree *T);

/**
 * @brief Restitue le dernier nœud de l'arbre \p T.
 * 
 * NB : le dernier nœud d'un arbre binaire complet se trouve au dernier
 * niveau le plus à droite possible.
 * 
 * @param[in] T 
 * @return TNode* 
 */
TNode *CBTreeGetLast(CBTree *T);

/**
 * @brief Permute les données des nœuds \p node1 et \p node2.
 * 
 * @param[in] node1 
 * @param[in] node2 
 */
void CBTreeSwapData(TNode *node1, TNode *node2);

#endif // _TREE_H_
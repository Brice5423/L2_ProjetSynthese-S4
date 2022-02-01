#ifndef _LIST_H_
#define _LIST_H_

/**
 * @brief
 * Liste générique homogène doublement chaînée
 */

/**
 * @brief Un élément d'une liste doublement chaînée contient
 * (+) une donnée (data),
 * (+) une référence (succ) à l'élément suivant, et
 * (+) une référence (pred) à l'élément précédent.
 */
typedef struct ListNode {
	void * data;
	struct ListNode * succ, * pred;
} LNode;

/**
 * @brief  Construit et initialise un nouveau nœud
 * d'une liste doublement chaînée.
 * 
 * @param[in] data Donnée à affecter au nouveau nœud.
 * @return LNode* Le nouveau nœud créé.
 */
LNode * newLNode(void* data);

/**
 * @brief Restitue la donnée du nœud \p node.
 * 
 * @param[in] node 
 * @return void* 
 */
void* getLNodeData(const LNode* node);

/**
 * @brief Restitue le successeur du nœud \p node.
 * 
 * @param[in] node 
 * @return LNode* 
 */
LNode* Successor(const LNode* node);

/**
 * @brief Restitue le prédécesseur du nœud \p node.
 * 
 * @param[in] node 
 * @return LNode* 
 */
LNode* Predecessor(const LNode* node);

/**
 * @brief Remplace la donnée du nœud \p node par \p newData.
 * 
 * @param[in] node 
 * @param[in] newData 
 */
void setLNodeData(LNode* node, void* newData);

/**
 * @brief Remplace le successeur du nœud \p node par \p newSucc.
 * 
 * @param[in] node 
 * @param[in] newSucc 
 */
void setSuccessor(LNode* node, LNode* newSucc);

/**
 * @brief Remplace le prédécesseur du nœud \p node par \p newSucc.
 * 
 * @param[in] node 
 * @param[in] NewPred 
 */
void setPredecessor(LNode* node, LNode* NewPred);

/**
 * @brief La liste est une structure contenant :
 * (+) une référence (head) sur son premier élément,
 * (+) une référence (tail) sur son dernier élément,
 * (+) le nombre d'éléments,
 * (+) un pointeur de fonction pour afficher ses données, et
 * (+) un pointeur de fonction pour libérer la mémoire de ses données.
 */
typedef struct List {
	LNode * head, * tail;
	int numelm;
	void (*viewData)(const void* data);
	void (*freeData)(void* data);
} List;

/**
 * @brief Construit et initialise une liste vide.
 * 
 * Les deux pointeurs de fonction passés en paramètre indiquent
 * de façon implicite le type de la donnée de la liste créée.
 * 
 * @param[in] viewData Pointeur de fonction pour afficher les données de la nouvelle liste.
 * @param[in] freeData Pointeur de fonction pour libérer la mémoire des données de la nouvelle liste.
 * @return List* La nouvelle liste créée.
 */
List * newList(void (*viewData)(const void*), void (*freeData)(void*));

/**
 * @brief Renvoie 1 si la liste \p L est vide, sinon renvoie 0.
 * 
 * @param[in] L 
 * @return int 
 */
int listIsEmpty(List* L);

/**
 * @brief Restitue la taille (nombre d'éléments) de la liste \p L.
 * 
 * @param[in] L 
 * @return int 
 */
int getListSize(const List* L);

/**
 * @brief Restitue la tête (premier élément) de la liste \p L.
 * 
 * @param[in] L 
 * @return LNode* 
 */
LNode* Head(const List* L);

/**
 * @brief Restitue la queue (dernier élément) de la liste \p L.
 * 
 * @param[in] L 
 * @return LNode* 
 */
LNode* Tail(const List* L);

/**
 * @brief Incrémente la taille de la liste \p L par 1.
 * 
 * @param[in] L 
 */
void increaseListSize(List* L);

/**
 * @brief Décrémente la taille de la liste \p L par 1.
 * 
 * @param[in] L 
 */
void decreaseListSize(List* L);

/**
 * @brief Met à jour la taille de la liste \p L à \p newSize.
 * 
 * @param[in] L 
 * @param[in] newSize 
 */
void setListSize(List* L, int newSize);

/**
 * @brief Réinitialise la taille de la liste \p L à zéro.
 * 
 * @param[in] L 
 */
void resetListSize(List* L);

/**
 * @brief Remplace la tête de la liste \p L par \p newHead.
 * 
 * @param[in] L 
 * @param newHead 
 */
void setHead(List* L, LNode* newHead);

/**
 * @brief Remplace la queue de la liste \p L par \p newTail.
 * 
 * @param[in] L 
 * @param[in] newTail 
 */
void setTail(List* L, LNode* newTail);

/**
 * @brief Deux possibilités pour liberer la memoire de la liste \p L :
 * (+) Si le paramètre \p deleteData vaut 0,
 *     alors les données (data) référencées par les éléments
 *     de la liste \p L ne sont pas supprimées ;
 * (+) Si le paramètre \p deleteData vaut 1,
 *     alors le pointeur de fonction freeData de la structure List
 *     va servir à supprimer les données (data) référencées par
 *     les éléments de la liste \p L.
 * 
 * @param[in] L 
 * @param[in] deleteData 
 */
void freeList(List * L, int deleteData);

/**
 * @brief Affiche les éléments de la liste \p L.
 * Les données de chaque élément sont affichées grâce au pointeur
 * de fonction viewData de la structure List.
 * 
 * @param[in] L 
 */
void viewList(const List * L);

/**
 * @brief Insère en tête de la liste \p L un nouveau nœud de donnée \p data.
 * 
 * @param[in] L 
 * @param[in] data
 */
void listInsertFirst(List * L, void * data);

/**
 * @brief Insère à la fin de la liste \p L un nouveau nœud de donnée \p data.
 * 
 * @param[in] L 
 * @param[in] data
 */
void listInsertLast(List * L, void * data);

/**
 * @brief Insère un nouveau nœud de donnée \p data dans la liste \p L
 * après le nœud indiqué par le pointeur \p ptrelm.
 * 
 * @param[in] L
 * @param[in] data
 * @param[in] ptrelm Ce pointeur désigne obligatoirement
 * 					un nœud de la liste \p L.
 */
void listInsertAfter(List * L, void * data, LNode * ptrelm);

/**
 * @brief Supprime le premier nœud de la liste \p L et restitue sa donnée.
 * La mémoire du nœud supprimé est libérée mais pas la mémoire de la donnée.
 * 
 * @param[in] L La liste ne doit pas être vide.
 * @return void* La donnée du nœud supprimé.
 */
void* listRemoveFirst(List * L);

/**
 * @brief Supprime le dernier nœud de la liste \p L et restitue sa donnée.
 * La mémoire du nœud supprimé est libérée mais pas la mémoire de la donnée.
 * 
 * @param[in] L La liste ne doit pas être vide.
 * @return void* La donnée du nœud supprimé.
 */
void* listRemoveLast(List * L);

/**
 * @brief Supprime le nœud de la liste \p L indiqué par le pointeur \p node
 * et restitue sa donnée.
 * La mémoire du nœud supprimé est libérée mais pas la mémoire de la donnée.
 * 
 * @param[in] L La liste ne doit pas être vide.
 * @param[in] node Ce pointeur désigne obligatoirement un nœud de la liste \p L.
 * @return void* La donnée du nœud supprimé.
 */
void* listRemoveNode(List * L, LNode * node);

/**
 * @brief Concatène les listes \p L1 et \p L2 :
 * (+) Si \p L1 n'est pas vide, lie la liste \p L2 à la fin de la liste \p L1
 * et restitue la liste \p L1 (la mémoire de la liste \p L2 est libérée,
 * mais pas ses nœuds).
 * (+) Sinon, restitue la liste \p L2 (la mémoire de la liste \p L1 est libérée).
 * 
 * @param[in] L1 
 * @param[in] L2 
 * @return List* 
 */
List* listConcatenate(List* L1, List* L2);

#endif // _LIST_H_
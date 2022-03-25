#ifndef _HEAP_H_
#define _HEAP_H_

/***************************************************
 * ARRAY HEAP
 ***************************************************/

/**
 * @brief Un tas implémenté par un tableau est une structure contenant:
 * (+) un tableau d'éléments génériques de type void*,
 * (+) la taille maximale/initiale du tableau,
 * (+) le nombre d'éléments existants actuellement au tableau,
 * (+) un pointeur de fonction pour comparer la priorité de 2 éléments,
 * (+) un pointeur de fonction pour afficher ses données, et
 * (+) un pointeur de fonction pour libérer la mémoire de ses données.
 */
typedef struct {
    void **A;
    int MAX;
    int N;

    int (*preceed)(const void *, const void *);

    void (*viewHeapData)(const void *);

    void (*freeHeapData)(void *);
} ArrayHeap;

/**
 * @brief Restitue la taille maximale du tas \p AH.
 * 
 * @param[in] AH 
 * @return int 
 */
int getAHMaxSize(const ArrayHeap *AH);

/**
 * @brief  Restitue la taille actuelle du tas \p AH.
 * 
 * @param[in] AH 
 * @return int 
 */
int getAHActualSize(const ArrayHeap *AH);

/**
 * @brief Restitue l'élément de la position \p pos du tas \p AH
 * 
 * @param[in] AH 
 * @param[in] pos
 * @return void* 
 */
void *getAHNodeAt(const ArrayHeap *AH, int pos);

/**
 * @brief Décrémente la taille du tas \p AH par 1.
 * 
 * @param[in] AH 
 */
void decreaseAHActualSize(ArrayHeap *AH);

/**
 * @brief Remplace l'élément de la position \p pos du tas \p AH
 * par \p newData
 * 
 * @param[in] AH 
 * @param[in] position 
 * @param[in] newData 
 */
void setAHNodeAt(ArrayHeap *AH, int position, void *newData);

/**
 * @brief Transforme le tableau \p A à un tas en réorganisant ses éléments
 * selon le pointeur de fonction \p preceed.
 * En fait, il s'agit du constructeur de ce type de tas
 *
 * Les deux pointeurs de fonction viewHeapData et freeHeapData indiquent
 * de façon implicite le type de la donnée du tas créée.
 *
 * @param[in] A Tableau générique
 * @param[in] N Taille du tableau \p A
 * @param[in] preceed Pointeur de fonction qui définit la relation de
 * priorité entre deux éléments du tas.
 * @param[in] viewHeapData Pointeur de fonction pour afficher les données
 * du nouveau tas.
 * @param[in] freeHeapData Pointeur de fonction pour libérer la mémoire
 * des données du nouveau tas.
 * @return ArrayHeap* Le nouveau tas créé.
 */
ArrayHeap *ArrayToArrayHeap(void **A, int N,
                            int (*preceed)(const void *, const void *),
                            void (*viewHeapData)(const void *),
                            void (*freeHeapData)(void *));


/**
 * @brief Affiche les éléments du tas \p AH.
 * Les données de chaque élément sont affichées grâce au pointeur
 * de fonction viewHeapData de la structure ArrayHeap.
 * 
 * @param[in] AH 
 */
void viewArrayHeap(const ArrayHeap *AH);

/**
 * @brief Deux possibilités pour liberer la memoire du tas \p AH :
 * (+) Si le paramètre \p deleteData vaut 0,
 *     alors les données (data) référencées par les éléments
 *     du tas \p AH ne sont pas supprimées ;
 * (+) Si le paramètre \p deleteData vaut 1,
 *     alors le pointeur de fonction freeData de la structure ArrayHeap
 *     va servir à supprimer les données (data) référencées par
 *     les éléments du tas \p AH.
 * 
 * @param[in] AH 
 * @param[in] deletedata
 */
void freeArrayHeap(ArrayHeap *AH, int deletedata);

/**
 * @brief Supprime du tas \p AH l'élément avec la plus grande priorité.
 * La mémoire de l'élément n'est pas libérée.
 * Au contraire, l'élément est restitué à la fin de la fonction.
 * 
 * @param[in] AH 
 * @return void* 
 */
void *ArrayHeapExtractMin(ArrayHeap *AH);

/***************************************************
 * COMPLETE BINARY TREE HEAP
 ***************************************************/

/**
 * @brief Un tas implémenté par un arbre binaire complet est 
 * une structure contenant:
 * (+) un arbre binaire complet,
 * (+) un pointeur de fonction pour comparer la priorité de 2 éléments,
 * (+) un pointeur de fonction pour afficher ses données, et
 * (+) un pointeur de fonction pour libérer la mémoire de ses données.
 */
typedef struct {
    CBTree *T;

    int (*preceed)(const void *, const void *);

    void (*viewHeapData)(const void *);

    void (*freeHeapData)(void *);
} CBTHeap;

/**
 * @brief Construit et initialise un arbre binaire complet vide.
 * 
 * Les deux pointeurs de fonction \p viewHeapData et \p freeHeapData
 * indiquent de façon implicite le type de la donnée de l'arbre créée.
 * 
 * @param[in] preceed Pointeur de fonction qui définit la relation de
 * priorité entre deux éléments du tas.
 * @param[in] viewHeapData Pointeur de fonction pour afficher les données
 * du nouveau tas.
 * @param[in] freeHeapData Pointeur de fonction pour libérer la mémoire
 * des données du nouveau tas.
 * @return CBTHeap* 
 */
CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
                    void (*viewHeapData)(const void *),
                    void (*freeHeapData)(void *));

/**
 * @brief Restitue l'arbre binaire complet implémentant le tas \p H.
 * 
 * @param[in] H 
 * @return CBTree* 
 */
CBTree *getCBTree(const CBTHeap *H);

/**
 * @brief Insère dans le tas \p H un nouveau nœud de donnée \p data.
 * 
 * @param[in] H 
 * @param[in] data 
 */
void CBTHeapInsert(CBTHeap *H, void *data);

/**
 * @brief Supprime du tas \p H l'élément avec la plus grande priorité.
 * La mémoire de l'élément n'est pas libérée.
 * Au contraire, l'élément est restitué à la fin de la fonction.
 * 
 * @param[in] H 
 * @return void* 
 */
void *CBTHeapExtractMin(CBTHeap *H);

/**
 * @brief Affiche les éléments du tas \p H.
 * Les données de chaque élément sont affichées grâce au pointeur
 * de fonction viewHeapData de la structure CBTHeap.
 * 
 * @param[in] H 
 */
void viewCBTHeap(const CBTHeap *H);

/**
 * @brief Deux possibilités pour liberer la memoire du tas \p H :
 * (+) Si le paramètre \p deletenode vaut 0,
 *     alors les données (data) référencées par les éléments
 *     de l'arbre T du tas \p H ne sont pas supprimées ;
 * (+) Si le paramètre \p deletenode vaut 1,
 *     alors le pointeur de fonction freeData de la structure CBTree
 *     va servir à supprimer les données (data) référencées par
 *     les éléments de l'arbre T du tas \p H.
 * 
 * @param[in] H 
 * @param[in] deletenode 
 */
void freeCBTHeap(CBTHeap *H, int deletenode);

#endif // _HEAP_H_
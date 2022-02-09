#ifndef _SORT_H_
#define _SORT_H_

/**
 * @brief
 * Algorithmes de tri.
 */

/**
 * @brief Tri par tas (implémenté par un tableau).
 * 
 * @param[in,out] A le tableau à trier
 * @param[in] N la taille du tableau
 * @param[in] preceed Pointeur de fonction qui définit la relation de
 * priorité entre deux éléments du tas.
 * @param[in] viewHeapData Pointeur de fonction pour afficher les données
 * du nouveau tas.
 * @param[in] freeHeapData Pointeur de fonction pour libérer la mémoire
 * des données du nouveau tas.
 */
void ArrayHeapSort(void **A, int N,
                   int (*preceed)(const void *, const void *),
                   void (*viewHeapData)(const void *),
                   void (*freeHeapData)(void *));

/**
 * @brief Tri par tas (implémenté par un arbre binaire complet).
 * 
 * @param[in,out] A le tableau à trier
 * @param[in] N la taille du tableau
 * @param[in] preceed Pointeur de fonction qui définit la relation de
 * priorité entre deux éléments du tas.
 * @param[in] viewHeapData Pointeur de fonction pour afficher les données
 * du nouveau tas.
 * @param[in] freeHeapData Pointeur de fonction pour libérer la mémoire
 * des données du nouveau tas.
 */
void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *));

/**
 * @brief Tri par sélection (tri par échange)
 *
 * @param[in,out] A le tableau à trier
 * @param[in] N la taille du tableau
 * @param[in] preceed Pointeur de fonction qui définit la relation de
 * priorité entre deux éléments du tas.
 */
void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *));

#endif // _SORT_H_
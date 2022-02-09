#ifndef _ALGO_H_
#define _ALGO_H_

/**
 * @brief Calcule l'enveloppe convexe d'un ensemble des points en 2D.
 * Algorithme glouton qui examine tous les couples de points.
 * 
 * @param[in] infilename le nom du fichier qui contient les points d'entrée
 * @param[in] outfilename le nom du fichier qui contiendra les points de
 * l'enveloppe convexe
 */
void SlowConvexHull(const char *infilename, const char *outfilename);

/**
 * @brief Calcule l'enveloppe convexe d'un ensemble des points en 2D.
 * Algorithme incrémental / itératif basé sur un tri.
 *
 * @param[in] infilename le nom du fichier qui contient les points d'entrée
 * @param[in] outfilename le nom du fichier qui contiendra les points de
 * l'enveloppe convexe
 * @param[in] sortby l'algorithme de tri à utiliser:
 *              (+) 1: tri par tas utilisant une structure arbre avec pointeurs
 *              (+) 2: tri par tas utilisant un tableau
 *              (+) 3: tri par sélection (tri par échange)
 */
void ConvexHull(const char *infilename, const char *outfilename, int sortby);

/**
 * @brief Calcule l'enveloppe convexe d'un ensemble des points en 2D.
 * Algorithme rapide qui considère les points de l'enveloppe convexe.
 * 
 * @param[in] infilename le nom du fichier qui contient les points d'entrée
 * @param[in] outfilename le nom du fichier qui contiendra les points de
 * l'enveloppe convexe
 */
void RapidConvexHull(const char *infilename, const char *outfilename);

#endif // _ALGO_H_
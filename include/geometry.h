#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

/**
 * @brief 
 * Définitions des éléments géométriques
 */

/**
 * @brief Structure qui correspond à un point contenant:
 * (+) l'abscisse, et
 * (+) l'ordonnée.
 */
typedef struct {
	long long int x;  // abscisse
	long long int y;  // ordonnée
} Point;

/**
 * @brief Construit et initialise un nouveau point.
 * 
 * @param[in] x L'abscisse à affecter au nouveau point.
 * @param[in] y L'ordonnée à affecter au nouveau point.
 * @return Point* Le nouveau point créé.
 */
Point* newPoint(long long int x, long long int y);

/**
 * @brief Restitue l'abscisse du point \p P.
 * 
 * @param[in] P 
 * @return long long int 
 */
long long int X(const Point* P);

/**
 * @brief Restitue l'ordonnée du point \p P.
 * 
 * @param[in] P 
 * @return long long int 
 */
long long int Y(const Point* P);

/**
 * @brief Affiche le point \p P.
 * 
 * @param[in] P 
 */
void viewPoint(const void* P);

/**
 * @brief Libère la mémoire du point \p P.
 * 
 * @param[in] P 
 */
void freePoint(void* P);

/**
 * @brief Teste si le point \p P est à droite de la droite définie par
 * les points \p origin et \p destination.
 *
 * @param[in] origin
 * @param[in] destination
 * @param[in] P
 * @return int 1 si \p P est à droite, 0 si \p P est à gauche.
 */
int onRight(const Point* origin, const Point* destination, const Point* P);

/**
 * @brief Teste si le point \p P est à gauche de la droite définie par
 * les points \p origin et \p destination.
 * 
 * @param[in] origin 
 * @param[in] destination 
 * @param[in] P 
 * @return int 1 si \p P est à gauche, 0 si \p P est à droite.
 */
int onLeft(const Point* origin, const Point* destination, const Point* P);

/**
 * @brief Teste si les points \p P, \p origin et \p destination
 * sont colinéaires.
 *
 * @param[in] origin
 * @param[in] destination
 * @param[in] P
 * @return int 1 si \p P, \p origin et \p destination sont colinéaires,
 * sinon 0.
 */
int collinear(const Point* origin, const Point* destination, const Point* P);

/**
 * @brief Teste si le point \p P est dans le segment entre \p origin
 * et \p destination
 * 
 * @param[in] origin 
 * @param[in] destination 
 * @param[in] P 
 * @return int 1 si \p P est dans le segment entre \p origin et
 * \p destination, sinon 0.
 */
int isIncluded(const Point* origin, const Point* destination, const Point* P);

/**
 * @brief Structure qui correspond à une arête orientée (arc) contenant:
 * (+) le point d'origine, et
 * (+) le point de destination.
 */
typedef struct DirectedEdge{
	Point* origin;  // début de l'arc
	Point* destination;  // fin de l'arc
} DEdge;

/**
 * @brief Construit et initialise un nouveau arc.
 * 
 * @param[in] origin Le point d'origine à affecter dans l'arc.
 * @param[in] destination Le point de destination à affecter dans l'arc.
 * @return DEdge* Le nouveau arc créé.
 */
DEdge* newDEdge(Point* origin, Point* destination);

/**
 * @brief Restitue le point d'origine de l'arc \p DE.
 * 
 * @param[in] DE 
 * @return Point* 
 */
Point* getOrigin(const DEdge* DE);

/**
 * @brief Restitue le point de destination de l'arc \p DE.
 * 
 * @param[in] DE 
 * @return Point* 
 */
Point* getDestination(const DEdge* DE);

/**
 * @brief Affiche l'arc \p DE.
 * 
 * @param[in] DE 
 */
void viewDEdge(const void* DE);

/**
 * @brief Libère la mémoire de l'arc \p DE.
 * 
 * @param[in] DE 
 */
void freeDEdge(void* DE);

#endif // _GEOMETRY_H_
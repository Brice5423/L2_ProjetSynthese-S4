#ifndef _UTILITIES_H_
#define _UTILITIES_H_

/**
 * @brief Fonction générique qui calcule et retourne le max entre
 * deux éléments de type numérique quelconque
 */
#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        _a > _b ? _a : _b; })

/**
 * @brief Fonction générique qui calcule et retourne le min entre
 * deux éléments de type numérique quelconque.
 */
#define min(a, b) \
    ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        _a < _b ? _a : _b; })

/**
 * @brief Affiche le message d'erreur \p msg et
 * interrompt l'exécution du programme si le paramètre \p interrupt vaut 1.
 * 
 * @param[in] msg 
 * @param[in] interrupt 
 */
void ShowMessage(char *msg, int interrupt);

/**
 * @brief Affiche l'entier de l'adresse mémoire \p i.
 *
 * @param[in] i le type de l'argument est de void* et pas de int*
 *          afin d'éviter un "warning" dans la compilation.
 */
void viewInt(const void *i);

/**
 * @brief Libère la mémoire de l'entier indiqué par le pointeur \p i.
 * 
 * @param[in] i le type de l'argument est de void* et pas de int*
 *          afin d'éviter un "warning" dans la compilation.
 */
void freeInt(void *i);

/**
 * @brief Compare les entiers \p a et \p b.
 * 
 * Le type des argument est de void* et pas de int*
 * afin d'éviter un "warning" dans la compilation.
 * 
 * @param[in] a 
 * @param[in] b 
 * @return int int 1 si a>b, sinon 0
 */
int intSmallerThan(const void *a, const void *b);

/**
 * @brief Compare les entiers \p a et \p b.
 * 
 * Le type des argument est de void* et pas de int*
 * afin d'éviter un "warning" dans la compilation.
 * 
 * @param[in] a 
 * @param[in] b 
 * @return int 1 si a>b, sinon 0
 */
int intGreaterThan(const void *a, const void *b);

#endif // _UTILITIES_H_
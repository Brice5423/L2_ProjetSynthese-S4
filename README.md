# L2_ProjetSynthese-S4
Projet de synthèse fait durant le S4 de la L2 Info.  
Projet fait par :
- [Brice ORLIANGE](mailto:briceorl54580@gmail.com), du groupe TP4
- [Matthieu FRITSCH](mailto:mattfritsch98380@gmail.com), du groupe TP4

________________________________________________________________________________________________________________________

# ⚠️ Indication pour le prof ‼️️⚠️

On a un problème incompréhensible, on ne connait pas la cause. On le signale, car il peut être **dangereux pour la RAM**.  
Pour certains jeux de point **l'exécution ne se termine pas** et **l'utilisation de la RAM fait que d'augmenter**.
Les jeux en questions sont :
 - `RapidConvexHull` avec la `data2`.
 - `SlowConvexHull` avec la `data2`, la `data3` et la `data4`

> On voulait juste signalé cette erreur "minime" pour éviter tout préjudice de votre coté. 😁 😀

________________________________________________________________________________________________________________________

# Consigne d'exécution
Voici les consignes d'exécution de ce projet.  

## 1. Model
Voici le model de la commande pour exécuté le main :
```shell
make; ./convexhull algo infilename outfilename sort     
```

## 2. Arguments
Voici une explication de chaque argument à utiliser pour lancer le projet.

### 2.1. Choix de l'algorithme `algo`
 - `s` : correspond à **SlowConvexHull**.
   - `c` : correspond à **ConvexHull**, on a besoin du `sort` :
   - `1` : CBTHeapSort
   - `2` : ArrayHeapSort
   - `3` : SelectionSort
 - `r` : correspond à **RapidConvexHull**.
 - `a` : correspond à **All**. _(execute tous les algorithmes avec les 4 fichiers data donnés)_

### 2.2. Fichier d'entrée et de sortie
Suivie de l'algorithme, utiliser entré les fichiers d'entrée et de sortie sous ce format :  
```
infilename outfilename
```

## 3. Exemple
Voici plusieurs exemples d'utilisation pour les différents algorithmes

### 3.1. SlowConvexHull
`./convexhull s infilename outfilename`

### 3.2 ConvexHull
#### 3.2.1. CBTHeapSort
`./convexhull c infilename outfilename 1`
#### 3.2.2. ArrayHeapSort
`./convexhull c infilename outfilename 2`
#### 3.2.3. SelectionSort
`./convexhull c infilename outfilename 3`

### 3.3 RapidConvexHull
`./convexhull r infilename outfilename`
### 3.4 TOUS
`./convexhull a infilename outfilename`

________________________________________________________________________________________________________________________

# RAPPORT DE PROJET
> Ce rapport est la version pour le README du projet !

## 1. Introduction
A travers ce rapport de projet de synthèse, nous allons vous montrer par quel moyen nous avons réalisé cette première partie en C.

Tout d'abord nous allons vous présenter quels outils nous avons utilisés pour développer cette première partie, 
notre outil de communication et notre outil de partage de code.  
Puis, nous allons vous présenter quelques fonctions que nous avons décidées de réaliser
pour ce projet afin de nous faciliter la tâche pour certaines tâches.
Nous allons également vous présenter les difficultés que nous avons pu rencontrer au cours de la réalisation du projet.  
Enfin, nous vous proposerons quelques améliorations qui selon nous pourrait améliorer la réalisation de ce projet.  
Vous pourrez également retrouver la répartition des tâches au sein de notre groupe et nos avis personnels 
pour chacun des points que nous allons traiter au cours du rapport. 


## 2. Outils utilisés
Liste des outils utilisés au cours du projet :
 - **CLion** : Développement de la partie en C du projet
   - **Code With Me** : Outil collaboratif de JetBrain.  
   _(Mélange du style CLion pour le code & Google Doc pour le partage)_
 - **GitHub** : Outil pour partager notre code entre nous.
 - **Discord** : Outil pour communiquer ensemble tout au long du projet.


## 3. Répartition des tâches

### 3.1 Partie 1 : Code C
La répartition des tâches pour faire chaque fichier _(fonctions)_ du projet :
- Brice :
   - tree.c
   - heap.c
   - sort.c
- Matthieu :
   - list.c
   - geometry.c
   - algo.c _(Brice est venu aider pour les dernières fonctions `convex`)_

Brice à formater tous les fichiers pour l'uniformité du code. _(Brice aime bien quand c'est ranger)_

### 3.2 Partie 2 : Interface & Compléxité
La répartition des tâches sont :
- Brice :
   - Complexité
   - Temps d'exécution
- Matthieu :
   - Interface
   - ...  <--------------------------------------------------------------


## 4. Fonctions importantes ajoutées
Nous avons implémenté quelques fonctions en plus qui nous ont été utiles pour le développement du projet
Voici la présentation de ces fonctions :
 - `static void organiseTableauEnTas(ArrayHeap *AH)` dans le `heap.c`, ajouté par Brice.  
Cette fonction appel la fonction `updateArrayHeapDownwards` dans tout les nodes se trouvant dans la couche `h - 1`.
`h` est le nombre de couches de l'arbre.


## 5. Complexité & temps d'exécution

### 5.1. Complexité du ConvexHull
Calcule de la complexité du ConvexHull en fonction des 3 tris _(sélection, tas tableau et tas arbre)_.

#### 5.1.1. Complexité du ConvexHull sans tri
On commence par calculé la complexité de la fonction `ConvexHull`  dans le pire des cas sans prendre en compte du tri.  

La complexité du `ConvexHull`, est de **N**.

**Explication** :  
Sa complexité est de **N**, car il y a la présence _(direct ou par appel de fonction)_ de plusieurs boucles "simples" de complexité de **N** chacune.  
On ne trouve rien d'autre qui a une complexité supérieur à N dans le rest de la fonction `ConvexHull`.

**Détail rapide des calculs** :  
````c
C(readInstance) + 2 * (C(for) + C(while)) + C(writeSolution) + C(freeList)
= N + C(tri) + 2 * ((N - 2) + (N - (N - 4))) + 2N + 2N // (N - 2) + (N - 4) C'est un extreme ++
= N + C(tri) + 2 * N + 2N + 2N
= 7N + C(tri) // On oublie le C(tri)
= N
````

#### 5.1.2. Complexité des tris
Voici la complexité de chaque tri de manière indépendante.

- **trie par arbre en tas** : N  
  Car il y a deux boucles `for` qui s'exécute **N fois** à la suite qui donne **2N** en complexité.
- **tri par tableau en tas** : N  
  Car il y a une présence d'une boucle qui s'exécute **N fois**.
- **tri par sélection** : N  
  Car il y a une boucle `for` à **N - i répétition** dans une boucle à **N répétition**.
  `i` est la nième itération du premier `for`.  
  Donc la complexité de la double boucle est de `N + (N - 1) + (N - 2) + (N - 3) + ...`

> Si on regarde avec un peu plus de détail, on remarque que le tri le plus optimal est le **tri par tableau en tas**.  
> La version la plus gourmande est avec le tri par sélection.

#### 5.1.3. Complexité du ConvexHull avec tri
Voici la complexité de chaque `ConvexHull` avec leur tri inclus.

- **trie par arbre en tas** : N  
  Car `C(ConvexHull sans tri) + C(tri) = N + N = N`.
- **tri par tableau en tas** : N  
  Car `C(ConvexHull sans tri) + C(tri) = N + N = N`.
- **tri par sélection** : N  
  Car `C(ConvexHull sans tri) + C(tri) = N + N = N`.


### 5.2. Temps d'exécution des 3 tries _(Convex)_

#### 5.2.1. CBTHeapSort
- **data1** : 0.001234 sec
- **data2** : 0.001220 sec
- **data3** : 0.001096 sec
- **data4** : 0.001142 sec

#### 5.2.2. ArrayHeapSort
- **data1** : 0.001275 sec
- **data2** : 0.000681 sec
- **data3** : 0.001346 sec
- **data4** : 0.001261 sec

#### 5.2.3. SelectionSort
- **data1** : 0.001234 sec
- **data2** : 0.000882 sec
- **data3** : 0.001200 sec
- **data4** : 0.001127 sec

#### 5.2.4. Moyenne du temps
Pour avoir une idée de quel des 3 tries est le plus performent dans notre programme,
on va faire la moyenne de chaque résultat en fonction de chaque type de tri.  

Les moyennes sont :
- **ArrayHeapSort** : 0.001140 sec
- **CBTHeapSort** : 0.001173 sec
- **SelectionSort** : 0.001110 sec

> Le tri le plus efficace d'après notre exécution de notre code est le tri par `SelectionSort` _(0.001110 sec)_.
> Cela est contradictoire avec la complexité calculée avant.  
> L'erreur est du au problème qu'on a dans notre code. 
> Pour rappel, notre code ne renvoie pas les bons résultats, donc pas fiable à 100%.

#### 5.2.5. Graphe

# !!! Mettre en place un graphe et expliqué pq avoir pris ça !!!

### 5.3. Complexité des 3 ConvexHull
Dans le cas du ConvexHull, on prend le tie le plus efficace des 3 tries proposés.  
Donc on prend le tri par `ArrayHeapSort`.

##### Complexité
- **RapidConvexHull** : N²  
  Car il y a une boucle `for` dans une boucle `do while`. 
  Le `for` fait N fois, le `do while` fait aussi N fois dans le pire des cas, on a donc `N * N`.
- **ConvexHull** : N
- **SlowConvexHull** : N^3  
  Car il y a une boucle `for` dans une boucle `for` qui est dans une boucle `for`.  
  Chaque boucle `for` dont N boucles, qui donne `N * N * N`.
  

### 5.4. Temps d'exécution des 3 ConvexHull
Dans le cas du ConvexHull, on prend le tri par `ArrayHeapSort`.

#### 5.4.1. RapidConvexHull
- **data1** : 0.000787 sec
- **data2** : _INFINI_
- **data3** : 0.000837 sec
- **data4** : 0.001237 sec

#### 5.4.2. ConvexHull
- **data1** : 0.001275 sec
- **data2** : 0.000681 sec
- **data3** : 0.001346 sec
- **data4** : 0.001261 sec

#### 5.4.3. SlowConvexHull
- **data1** : 0.001416 sec
- **data2** : _INFINI_
- **data3** : _INFINI_
- **data4** : _INFINI_

#### 5.4.4. Graphe

# !!! Mettre en place un graphe et expliqué pq avoir pris ça !!!


## 6. Difficultés rencontrées
Tout au long du développement nous avon seu plus ou moins de mal à réaliser certaines tâches.
Voici une liste de quelques difficultés rencontrées avec leur explication.
_(Voir à la fin du projet)_


## 7. Améliorations possibles
_(Voir à la fin du projet)_


## 8. Conclusion
_(Voir à la fin du projet)_

________________________________________________________________________________________________________________________

# Utilisation des commits
Chaque étape correspond à comment on écrie un commit.
> Au cours de ce projet, nous avons essayé de respecter notre nomenclature présentée ci-dessous.  
> _(Notre nomenclature à évoluer au fil du projet, en fonction de nos besoins.)_

## 1. Importance des commits

 - 🟥 : Très important _(si notre vie était en jeu, très rare)_
 - 🟧 : Important _(fonction entière, code plus volumineux)_
 - 🟨 : Normale _(fonction partielle, code peu volumineux)_
 - 🟩 : Peu important _(commentaire, formatage, renommage, norme de codage, etc.)_

> Les emojis 🟩, 🟨, 🟧, 🟥 sont obtenus avec la touche `windows` + `;`.

## 2. Action des commits

 - **+** : ajout
 - **~** : modification
 - **-** : suppression

## 3. Fichier/dossier cible & Détaille

Pour savoir ce qu'on a fait après avoir indiqué l'importance du commit _(🟩, 🟨, 🟧, 🟥_ et quelle action _(+, ~, -)_,
on indique dans quels fichiers ça était appliqué.  
Si l'action ce porte dans l'ensemble des éléments d'un dossier, nous l'indiquerons par des `[nom_dossier]`.

On _(peut)_ ajoute entre `(...)`, les détails de l'action fait sur les fichiers concerner.  
S'il y a plusieurs fichiers qui ont les mêmes détaille, on met un `,` entre chaque nom de fichier (ou dossier).

**Exemple :**
```
🟩 ~ fichier1, fichier2 (commentaire & format) 
```
> Le commit indique que le `fichier1` et le `fichier2` ont eu une modification dans leurs commentaires et un formatage.

## 4. Importances et actions en commun

On met un `&` entre chaque fichier/dossier cible avec son détaille _(s'il y a)_ et on indique à nouveau la cible avec son détaille si besoin.

**Exemple :**
```
🟩 + fichier1 (commentaire) & fichier2 (format)
```
> Le commit indique que le `fichier1` à eu une modification dans ces commentaires et que le `fichier2` à fait un formatage.

## 5. Importances et/ou actions différents

Après avoir donnée l'importance et l'action avec leurs cibles et détailles.  
On recommence directement par indiquer l'importance puis son action pour montrer qu'on n'a pu la même importance et/ou action dans les cibles qui suivent.

**Exemple :**
```
🟧 + fichier1 (fonction1) 🟩 - fichier1 (commantaire)
```
> Le commit  indique que le `fichier1` à ajouté une fonction et qu'il a supprimé un commentaire.

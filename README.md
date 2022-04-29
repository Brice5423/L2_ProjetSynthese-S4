# L2_ProjetSynthese-S4
Projet de synthèse fait durant le S4 de la L2 Info.  
Projet fait par :
- [Brice ORLIANGE](mailto:briceorl54580@gmail.com), du groupe TP4
- [Matthieu FRITSCH](mailto:mattfritsch98380@gmail.com), du groupe TP4

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

#  RAPPORT DE PROJET

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

## 3. Fonctions importantes
Nous avons implémenté quelques fonctions en plus qui nous ont été utiles pour le développement du projet
Voici la présentation de ces fonctions :
- `static void organiseTableauEnTas(ArrayHeap *AH)` dans le `heap.c`. Il y a une doc liée avec la fonction.

## 4. Difficultés rencontrées
Tout au long du développement nous avon seu plus ou moins de mal à réaliser certaines tâches.
Voici une liste de quelques difficultés rencontrées avec leur explication.
###### ALL / TOUT / Ensemble de l'univers du projet ^^

## 5. Améliorations possibles
_(Voir à la fin du projet)_

## 6. Répartition des tâches 

### 6.1 Pour la partie en C
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

### 6.2 Pour la partie en interface
_(Voir à la fin du projet)_

## 7.  Compléxité & temps
_(Voir à la fin du projet, pas à faire pour le moment)_

### 7.1. Compléxité du programme
_(Voir à la fin du projet)_

### 7.2. Temps d'exécution 
_(Voir à la fin du projet)_

# Conclusion
_(Voir à la fin du projet)_

________________________________________________________________________________________________________________________

# Utilisation des commits
Chaque étape correspond à comment on écrie un commit.
> Au cours de ce projet, nous avons essayé de respecter notre nomenclature présentée ci-dessous.  
> _Notre nomenclature à évoluer au fil du projet, en fonction de nos besoins._

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
S'il y a plusieurs fichier qui ont les mêmes détaille, on met un `+` entre chaque nom de fichier.

**Exemple :**
```
🟩 ~ fichier1 + fichier2 (commentaire & format) 
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

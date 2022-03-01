# L2_ProjetSynthese-S4
Projet de synthèse fait durant le S4 de la L2 Info.  
Projet fait par :
- [Brice ORLIANGE](mailto:briceorl54580@gmail.com), du groupe TP4
- [Matthieu FRITSCH](mailto:mattfritsch98380@gmail.com), du groupe TP4

--------------------------------------

# 1. Utilisation des commits
Chaque étape correspond à comment on écrie un commit.

## 1.1. Importance des commits

- 🔴 : Très important _(si notre vie était en jeu, très rare)_
- 🟠 : Important _(fonction entière, code plus volumineux)_
- 🟡 : Normale _(fonction partielle, code peu volumineux)_
- 🟢 : Peu important _(commentaire, formatage, renommage, norme de codage, etc.)_

> Les emojis 🟢, 🟡, 🟠, 🔴 sont obtenus avec la touche `windows` + `;`.

## 1.2. Action des commits

- **+** : ajout
- **~** : modification
- **-** : suppression

## 1.3. Fichier/dossier cible & Détaille

Pour savoir ce qu'on a fait après avoir indiqué l'importance du commit _(🟢, 🟡, 🟠, 🔴)_ et quelle action _(+, ~, -)_,
on indique dans quels fichiers ça était appliqué.  
Si l'action ce porte dans l'ensemble des éléments d'un dossier, nous l'indiquerons par des `[nom_dossier]`.

On _(peut)_ ajoute entre `(...)`, les détails de l'action fait sur les fichiers concerner.  
S'il y a plusieurs fichier qui ont les mêmes détaille, on met un `+` entre chaque nom de fichier.

**Exemple :**
```
🟢 ~ fichier1 + fichier2 (commentaire & format) 
```
> Le commit indique que le `fichier1` et le `fichier2` ont eu une modification dans leurs commentaires et un formatage.

## 1.4. Importances et actions en commun

On met un `&` entre chaque fichier/dossier cible avec son détaille _(s'il y a)_ et on indique à nouveau la cible avec son détaille si besoin.

**Exemple :**
```
🟢 + fichier1 (commantaire) & fichier2 (format)
```
> Le commit indique que le `fichier1` à eu une modification dans ces commentaires et que le `fichier2` à fait un formatage.

## 1.5. Importances et/ou actions différents

Après avoir donnée l'importance et l'action avec leurs cibles et détailles.  
On recommence directement par indiquer l'importance puis son action pour montrer qu'on n'a pu la même importance et/ou action dans les cibles qui suivent.

**Exemple :**
```
🟠 + fichier1 (fonction1) 🟢 - fichier1 (commantaire)
```
> Le commit  indique que le `fichier1` à ajouté une fonction et qu'il a supprimé un commentaire.

--------------------------------------
# Le jeu du pendu (Hangman)

## Principe du jeu

Un mot secret est choisis aléatoirement dans une dictionnaire de mot français. Le but du jeu est de reconstruire le mot en devinant les lettres qui le compose. Il y a un nombre d'essais limité, chaque lettre juste ne compte pas pour un essai, mais 6 essai mène à une défaite.

## Lancer le programme

Pour le lancer le programme il faudra compiler le projet, c'est à dire se rendre dans le fichier où se trouve le fichier Makefile, et tapez la commande suivante.

```
make
```

Le projet une fois compilé donnera un exécutable qui se lance avec la commande suivante.

```
./Hangman
```

## Fonctionnalités

Le programme Hangman comprends le jeu du pendu, et un système de score.

- Le jeu est séparé en deux parties :
  - une partie dictionnaire permettant d'accéder facilement un mot aléatoire du dictionnaire.
  - la partie principale du jeu, attendant les actions du joueur et procédant à la révélation des lettres trouvés.
- Le score se fait sous forme de profil, un possède un pseudo ainsi que les statistiques de victoires, et de parties totales jouées. Les profils sont stockés sous forme de fichier textes, et il n'y a pas de limite de profil.

## Version

Hangman v1.0

## TO-DO

- Empêcher de réécrire plusieurs fois la lettre
- Empêcher de mettre des caractères qui ne sont pas des lettres
- Faire un menu plus beau
- Faire un un menu qui affiche les meilleurs profils
- Ajouter des paramètres à l'exécutable pour utiliser le dictionnaire de notre choix.
- Améliorer l'affichage du jeu
- Ajouter de la documentation

## Fichiers

- Makefile
- README.md
- en-tête
  - game.h
  - dict.h
  - profile.h
  - utils.h
- sources
  - main.cpp
  - game.cpp
  - dict.cpp
  - profile.cpp
  - utils.cpp
- données
  - dico.txt

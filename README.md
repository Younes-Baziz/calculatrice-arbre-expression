# Calculatrice à arbre d'expression

Projet réalisé en C++ dans le cadre de la Licence 1 Informatique à Avignon Université.

Cette application permet d'analyser, transformer et évaluer des expressions arithmétiques en s'appuyant sur plusieurs structures de données fondamentales telles que les piles chaînées et les arbres binaires d'expression.

## Fonctionnalités

- Conversion d'expressions infixées vers la notation postfixée (algorithme Shunting Yard)
- Évaluation d'expressions postfixées à l'aide d'une pile chaînée
- Construction d'arbres binaires d'expression
- Évaluation récursive des arbres générés
- Affichage des expressions en notation infixée avec parenthésage
- Dérivation symbolique par rapport aux variables X, Y ou Z

## Exemple

Expression infixée :

(3 + 5) * 2

Conversion postfixée :

3 5 + 2 *

Arbre d'expression :

        *
       / \
      +   2
     / \
    3   5

Résultat :

16

## Technologies utilisées

- C++
- Programmation Orientée Objet (POO)
- Piles chaînées
- Arbres binaires
- Récursivité
- Algorithme Shunting Yard

## Structure du projet

- `main.cpp` : point d'entrée du programme
- `fichier.hpp` : déclarations des classes et structures
- `fichier.cpp` : implémentation des algorithmes et traitements

## Compilation

```bash
g++ -o calc main.cpp fichier.cpp

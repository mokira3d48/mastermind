# MasterMind
Le but de ce jeu est de découvrir les numéros (de 1 à 9 pris au hasard)
contenus dans cinq cases cachées. Voici un exemple de combinaison pour ces
cinq cases cachées :

| 3 | 1 | 3 | 6 | 1 |
|---|---|---|---|---|

Pour découvrir cette combinaison, le joueur va lui-même proposer des
combinaisons. Après chaque proposition, on lui indique le nombre de numéros
corrects et bien placés. S’il propose :

| 3 | 3 | 5 | 3 | 1 |
|---|---|---|---|---|

Il lui sera répondu : 2 numéros bien placés. <br/>
En effet, le numéro 3 de la première case et le numéro 1 de la cinquième
correspondent à ceux de la combinaison cherchée.
Le joueur dispose d’un nombre maximum de coups pour jouer et trouver
la bonne combinaison.

On simule ce jeu à l’aide d’un programme qui devra :

- initialiser le jeu en créant au hasard la combinaison cachée,
- saisir successivement les propositions du joueur,
- les analyser,
- afficher le résultat de l’analyse, et ce, jusqu’à ce que le joueur ait
trouvé la bonne combinaison, ou qu’il ait joué le nombre maximum de coups
autorisés.

Le programme devra enfin afficher le résultat de ce jeu :

- bravo, vous avez gagné en ... essais !<br/>
ou au contraire :

- vous avez perdu ! La bonne combinaison était :

<u>**Question**</u>: Ecrire le programme C/C++ qui permet de simuler ce jeu du
Mastermind.


## Compilation
Pour compiler le programme, vous pouvez exécuter une des lignes de commande
suivante :

- sous linux :

```sh
gcc main.c -o bin/mastermind
```

Cette commande utilise seulement le compilateur `gcc` pour compiler
les sources.

ou

```sh
make
```
Alors que celle-ci utilise en plus du compilateur, mais aussi le programme
`cmake` pour compiler le programme.


## Exécution
Pour exécuter le programme :
	- sous linux :

```sh
./bin/mastermind
```

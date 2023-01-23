Ce projet vous demande de trier des données dans une pile, en utilisant un set

d’instructions limité, et avec le moins d’opérations possibles. Pour le réussir, vous

devrez manipuler diﬀérents algorithmes de tri et choisir la (ou les ?) solution la plus

appropriée pour un classement optimisé des données.


Le projet Push swap est un exercice d’algorithmie simple et eﬃcace : il faut trier de

la donnée.

Vous avez à votre disposition un ensemble d’entiers, deux piles et un ensemble d’instructions

pour manipuler celles-ci.

Votre but ? Écrire un programme en C nommé push\_swap qui calcule et aﬃche sur

la sortie standard le plus petit programme, fait d’instructions du langage Push swap,

permettant de trier les entiers passés en paramètres.



Objectifs

Écrire un algorithme de tri est toujours une étape importante dans la vie d’un

programmeur débutant car il s’agit souvent de la première rencontre avec la notion de

[complexité](https://en.wikipedia.org/wiki/Analysis_of_algorithms).

Les algorithmes de tri et leur complexité font parti des grands classiques des entretiens

d’embauche. C’est donc l’occasion rêvée pour vous pencher sérieusement sur la question

car soyez certains que cela vous sera demandé.

Les objectifs de ce projet sont la rigueur, la pratique du C et l’usage d’algorithmes

élémentaire. En particulier, la complexité de ces algorithmes élémentaire.

Trier des valeurs c’est simple. Les trier le plus vite possible, c’est moins simple vu

que, d’une conﬁguration des entiers à trier à une autre, un même algorithme de tri n’est

pas forcément le plus eﬃcace...




Partie obligatoire

V.1 Les règles

• Le jeu est constitué de 2 [piles](https://en.wikipedia.org/wiki/Stack_\(abstract_data_type\))[ ](https://en.wikipedia.org/wiki/Stack_\(abstract_data_type\))nommées a et b.

• Au départ :

◦ La pile a contient une quantité aléatoire de négatif et/ou des nombres positifs

qui ne peuvent pas être dupliqués.

◦ La pile b est vide.

• Le but du jeu est de trier les nombres de la pile a par ordre croissant. Pour ce

faire, vous disposez des instructions suivantes :

sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.

Ne fait rien s’il n’y en a qu’un ou aucun.

sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.

Ne fait rien s’il n’y en a qu’un ou aucun.

ss : sa et sb en même temps.

pa (push a) : Prend le premier élément au sommet de b et le met sur a.

Ne fait rien si b est vide.

pb (push b) : Prend le premier élément au sommet de a et le met sur b.

Ne fait rien si a est vide.

ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.

Le premier élément devient le dernier.

rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.

Le premier élément devient le dernier.

rr : ra et rb en même temps.

rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de

la pile a. Le dernier élément devient le premier.

rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de

la pile b. Le dernier élément devient le premier.

rrr : rra et rrb en même temps.


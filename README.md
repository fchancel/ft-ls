# FT_LS

## Challenge

Réecrire la fonction `ls`.

La fonction ne doit en aucun cas avoir de leaks.

Chaque erreur doit être gérer avec soin. 

La fonction ne doit pas quitter de manière inattendu (Segmentation fault, bus error, double free, etc).

Fonction autorisé pour la réecriture de `ft_ls`:

`write`, `opendir`, `readdir`, `closedir`, `stat`, `lstat`, `getpwuid`, `getgrgid`, `listxattr`, `getxattr`, `time`, `ctime`, `readlink`, `malloc`, `free`, `perror`, `strerror` and `exit`.
Tout autre fonction est interdite.

## Utilisation

Pour la compilation, lancer `make`.
Puis suivre l'usage: 

`usage: ft_ls [-FRSadfilrt1] [file ...]` 

### Flags

`-a` Affiche les fichiers caché

`-d` Les répertoires sont répertoriés comme des fichiers simples (non recherchés récursivement).

`-f` La sortie n'est pas triée

`-i` Affiche la numéro de série (numéro inode)
Basic functions:

`-l` Affiche la liste au format long

`-r` Trie inversé

`-t` Trie par heure de dernière modification

`-F` Affichage après le nom de chemin: / répertoire, * exécutable, lien @sym, = socket,% whiteout, | FIFO.

`-R` Recherche récusrivement dans les répertoires

`-S` Trie par taille de fichier

`-1` Force la sortie à une entré par ligne

## Démonstration

![Démonstration ft_ls](https://raw.githubusercontent.com/fchancel/ft-ls/master/img/ft_ls1.gif)

![Démonstration ft_ls](https://raw.githubusercontent.com/fchancel/ft-ls/master/img/ft_ls2.gif)

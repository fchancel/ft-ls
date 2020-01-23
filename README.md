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

Basic functions:

-l, -R, -a, -r, -t.

Bonus:

-F -S -d -f -i -1, column display, color display

![Démonstration ft_ls](https://gitlab.com/fchancel/ft_ls/raw/master/img/ft_ls1.gif)

![Démonstration ft_ls](https://gitlab.com/fchancel/ft_ls/raw/master/img/ft_ls2.gif)
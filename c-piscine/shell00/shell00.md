# J01
https://www.youtube.com/playlist?list=PLVQYiy6xNUxxhvwi0PGmXb5isUdVwmsg8

## ex02
pour déterminer le timestamp d'un fichier
```
touch -t 06012342 testShell0
```
l'exemple ci-dessus indique la date de 01 Juin à 23:42

parfois on a un `@` qui indique que le fichier à des attributs étendues comme ici (le symbole `@`)
```shell
-r--r-xr-x@  1 belmouss  staff    40  1 jui 23:42 testShell00
```
pour enlever on peut utiliser la commande `xattr filename`
https://stackoverflow.com/a/4833168

pour extraire un fichier tar on utilise la commande :
```
tar -xvf filename.tar
```

## ex03
la première lettre `l` dans l'affichage suivant indique que c'est un lien symbolique
```bash
lrwxr-xr-x 1 XX XX 5 Jun 1 22:20 test6 -> test0
```
on peut utiliser la commande `ln -s test6 test0` (-s permet de ne pas augmenter le nombre de `hard link`)
pour changer le timestamp d'un symlink on utilise l'option `h` comme suivant
```
touch -h -t 201301291810 myfile.txt
```
https://unix.stackexchange.com/a/63877

`ln test2 test5` permet de mettre à 2 le nombre de hard link
```
dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
-r-----r-- 2 XX XX  1 Jun 1 23:44 test5
```

## ex04
```
ls -mtUp
```
- m : séparation par virgule
- tU : le `t` trie par modification mais avec `-U` trie par création
- p : pour afficher les `/` pour les répertoires


## ex06
https://prograide.com/pregunta/3236/afficher-les-fichiers-ignores-dans-git
`git ls-files` liste tous les fichiers et à pluseurs paramètres pour filtrer
- `other` pour les fichiers untracked
- `i` pour les fichiers ignorer qui a besoin d'un exlcude pattern (--exclude-standard -> .gitignore)

## ex07
```
patch a sw.diff -o b
```

## ex08
```
find . -type f -name #\*# -delete -print -o -name \*~ -delete -print
```
`. -type f` : pour tous les fichier de type file
`delete` et `print` pour supprimer et imprimer

### Commandes de base
liste avec les détails et les fichiers cachés
```
ls -la
```

## File system
le file system est l'arborescence des fichiers dans le disque dur
```
drwxrwxrwx
```
le premier `d` indique ce c'est un `directory` 
information sur le fichier sous le format suivant
```
access user group size date name
```

## Commandes utiles
la commande `cat` (ConcATenate) permet d'afficher un fichier diretement dans le terminal
la commande `chmod` (Change MODe) pour modifier les permissions d'accès
```
chmod 000 file // ---------
chmod 700 file // rwx------
chmod 644 file // rw-r--r--
```

## Affichage
`echo "string"` pour afficher dans la sortie standard
`cat -e` pour afficher les caractères invisibles (`$` pour le retour à la ligne)
la commande `more` ou `less` pour afficher dans la sortie standard avec des fonctionnalités plus avancées
permet faire de la recherche et de se déplacer

## Filtrage
il y a trois commandes à connaître
les commandes `head` ou `tail` pour afficher les 10 premières/dernières lignes
la commande `grep` (global regular expression print) pour filtrer de manière efficace
```
grep Mathieu file
```
pour afficher les lignes qui contiennent `Mathieu`.
il faut regarder le manuel pour voir toutes les possibilités

## Redirection
la sortie standard s'affiche sur l'écran
pour que la sortie soit un fichier et pas l'écran on utilise le symbole `>` :
```
echo "bonjour" > file
```
ou le symbole `>>` double redirection droite pour ajouter du contenu dans un fichier
```
echo "bonjour" > file
```
pour rediriger vers une autre commande on utilise le symbole `|` (pipe)
```
cat file.txt | grep "Mathieu" | head -n 1
// affiche la première occurence de "Mathieu" du fichier file.txt
```
le fichier est stocké dans le premier `|` qui est réutilisé par le `grep` qui mettre la sortie dans le deuxième pipe qui est lui même réutilisé par la commande `head -n 1` pour afficher la première ligne.

## Modification
pour trier la sortie par ordre alphabétique
```
cat file.txt | sort
```

la commande `cut` permet de découper les sorties
```
cat file.txt | sort | cut -d , -f 1
// le cut découpe à partir d'une virgule (`-d ,`) et récupére seulement le premier champ (`f 1`)
```

pour les modifications on utilise la commande `sed` (Stream EDitor)
pour réaliser un remplacement (substitution)
on peut utiliser les regex avec les `sed`
```
sed "s/thomas/Thomas/"
```

la commande `tr` pour remplacer une chaîne de caractère
```
tr "éx" "eX"
```

## Autres Commandes
- la commande `wc` pour les statistiques d'un fichier
```
lignes mots caractères nom
```
pratique pour compter le nombre de résultat avec la commande `-l`
- la commande `file` pour avoir plus d'informations sur le fichier
- la commande `ifconfig` pour les informations de l'ordinateur (l'adresse ip)
- la commande `bc` pour une calculatrice scientifique
- la commande `find` pour une recherche récursive avec des options de filtrage
c'est une commande puissante à voir le manuel
- `env` est l'environnement avec toutes les variables
on peut ajouter un paramètre avec la commande `export NAME=3` et le réutiliser avec `$NAME`

## Bonus++
il y a deux types de sorties (la standard et l'erreur)
la sortie d'erreur est utiliser pour afficher une erreur

pour lire une sortie d'erreur dans la sortie standard on utilise `2>&1` ou `2>file` pour afficher l'erreur dans un fichier
- 2 est la sortie d'erreur
- 1 est la sortie standard
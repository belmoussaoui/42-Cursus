# Pipex
## les redirections
https://dev.to/oyagci/shell-redirections-explained-2h9

l'opérateur `>` et `>>` permet de rediriger la sortie dans un fichier (`>>` ajoute du contenu dans le fichier)

l'opérateur `<` permet de lire dans l'input comme par exemple
```
cat < a.txt
```

l'opérateur `<<` permet d'obtenir l'input de l'utilisateur ligne par ligne jusqu'au delimiter
```
cat << EOF
```

## les pipes
https://www.rozmichelle.com/pipes-forks-dups/
```
sort << EOF | grep ea
```
![](https://www.rozmichelle.com/wp-content/uploads/pipe-1.png)

> Well, since each command in the pipeline is run in a separate process, each command has its own version of the file descriptors, including its own stdin, stdout, and stderr. 

dans la manière que cela fonctionne
![](https://www.rozmichelle.com/wp-content/uploads/pipe20.png)

https://www.youtube.com/watch?v=6xbLgZpOBi8

https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901

la fonction `pipe` va créer deux fd qui sont liéés pour lesquels l'un va être utilisé pour lire et l'autre pour écrire

## tests
- unset path
- command `""` retourne `permission denied` (`F_OK`)
- protection des fonctions et des mallocs
# get_next_line
https://42born2code.slack.com/archives/CMX2R5JSW/p1643812138810249
## variable statique
https://www.delftstack.com/fr/howto/c/static-variable-in-c/
une variable non initialisée peut indiquer n'importe quelle valeur ce qui est différent de `null`
```C
char	*str1;
printf("%s\n", *str1); // %
char	*str2 = NULL;
printf("%s\n", *str1); // (null)%
```
les variable statiques sont initialisées automatiquement à `0` (`NULL` pour un pointeur)
les deux instructions suivantes sont similaires
```C
static char	*buffer = NULL;
static char	*buffer;
```
une variable statique permet de préserver la valeur entre les appels de fonction en `C`
la durée de vie d'une variable statique est jusqu'à la fin du programme

## fuites mémoire
https://www.examplefiles.net/cs/284539
un malloc qui est est pas free mais reste accessible **n'est pas une fuite mémoire**
le système d'exploitation moderne va automatiquement la libérée à la fin du programme (https://stackoverflow.com/a/34383266/17355718)
valgrind nomme les malloc qui sont accessibles des **still reachable**
une fuite mémoire c'est lorsqu'on perd l'adresse du malloc car il a était assigner à une nouvelle variable

pour tester des leaks à la fin du main avant le return
```C
system("leaks a.out");
```
valgrind et -fsanitize=address n'a jamais fonctionné chez moi :-(

## algorithme
on utiliser un buffer en statique pour enregistrer ce qu'on lit en trop
ce buffer va être utiliser pour le prochain appel à get next line

le reader contient les données qu'on lit jusqu'a rencontrer un `\n` ou un `eof`
comme on utilise un buffer size on peut lire plus de ce qu'on a besoin
le reader est donc sous cette forme :
```
reader = 'h' 'e' '...' 'w' '\n' 'o' 'k' '...' '\0'
```
à partir de reader on obtient la ligne qu'on veut retourner
c'est tous les caractères  vant le '\n' compris avec un `\0` qu'on ajoute
```
line = 'h' 'e' '...' 'w' '\n' '\0'
```
à partir de reader on obtient le nouveau buffer pour le prochain appel à get next line
c'est tous les caractères après le '\n' non compris avec le `\0`
```
buffer = 'o' 'k' '...' '\0'
```
ainsi au prochain appel on initialise le `reader` avec le buffer et on fait de même


## tests
* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

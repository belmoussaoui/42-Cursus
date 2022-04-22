# Libft
## Library
https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html

**comment créer une librairie ?**
```shell
ar -rcs libft.a *.o
```
- `r` insert les fichiers `.o` dans la bibliotheque
- `c` crée la bibliothéque s'il n'existe pas
- `s` est equivalent a `ranlib` pour créer un tableau d'index pour que le compilateur retrouve les fonctions plus rapidement


**comment utiliser la libft dans un autre projet ?**
- copier/coler la libft dans le projet
- ajouter une régle qui va compiler la libft
```makefile
libft:
	make -C ./libft/
```
- spécifier l'emplacement de la libft avec le paramètre `-L` et le nom de la librairie avec le paramètre `-l` (référence lib) dans la compilation du projet
```bash
gcc -Wall -Wextra -Werror main.c -L../ -lft
```

## Cast
le cast consiste à convertir un type de donnée en une autre

**comment cast un élément d'un array de type `void *` ?**

l'instruction suivante ne fonctionne pas car le compilateur ne connait pas la taille de `cols[1]` car son type est `void`
```C
(int) cols[1];
```
il faut donc d'abord convertir l'adresse en premier pour définir la taille de l'élément
```C
((int *) cols)[1];
```
https://stackoverflow.com/a/43564315/17355718

## Makefile
que fait la ligne de commande suivante ?

```makefile
$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

- `$<` spécifie le premier `prerequisites` (`%.c`) pour obtenir tous les fichiers sources nécessaires
- `$@` spécifie la `targets` (`$(OBJS_DIR)%.o`) pour obtenir tous les fichiers objets nécessaires

le format d'une commande d'un makefile
```makefile
targets: prerequisite1 prerequisite2
	command
	command
	command
```
https://stackoverflow.com/a/26133524/17355718
https://stackoverflow.com/a/3220288/17355718


**comment placer les fichiers objets dans un dossier séparé ?**
```makefile
$(OBJDIR)/%.o: %.c
    $(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
```
https://stackoverflow.com/a/5188496/17355718

## Tests
* [Tripouille/libfTester](https://github.com/Tripouille/libftTester)
* [ska42/libft-war-machine](https://github.com/ska42/libft-war-machine)
* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)

- ft_atoi (overflow)
- ft_lstdelone (toujours free la liste)
- ft_split static et free
- ft_memmove explication
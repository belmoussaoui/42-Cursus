# J02
https://www.youtube.com/playlist?list=PLVQYiy6xNUxxhvwi0PGmXb5isUdVwmsg8
## ex01
- `G`
display the different group IDs as white-space separated numbers
- `n`
display the name to use with g
## ex02
la commande suivante permet de supprimer les chemins
```
sed 's!.*/!!'
```
les poinys dexclamation on le meme effet que le \
sans la commande = `./dossier/sous`
avec la commande = `sous`

## ex03
la command find touve tous les fichiers et les affiches sous forme de ligne et donc il faut utiliser `-l` pour compter le nombre de lignes
la commande `wc` cree une tabulation qui peut être supprimer par `tr -d ' '`


## ex04
`ether ` avec un espace pour eviter les lignes qui ont le mot ethernet
decoupage de la ligne pour choisir juste l adresse  
```
ifconfig | grep "ether " | cut -d ' ' -f 2
```

## ex05
pour creer un fichier avec des caracteres speciaux
```
\"\\\?\$\*\'MaRViN\'\*\$\?\\\"
```
https://stackoverflow.com/a/49988431/17355718

 ## ex06
 https://www.gnu.org/software/sed/manual/sed.html#Common-Commands
 pour afficher une ligne sur deux en commencant par la premiere ligne
`ls -l | sed -n 'n;p'`

`-n` permet de skip des lignes selon un pattern

pour afficher une ligne sur deux en commencant par la deuxieme ligne
`ls -l | sed -n 'p;n'`

- `-n`: suppress printing
- `p`: print current line
- `n`: next line
https://stackoverflow.com/a/41745739
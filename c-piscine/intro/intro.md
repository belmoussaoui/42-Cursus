# Intro
https://www.youtube.com/watch?v=a14XiTXjOow&list=PLVQYiy6xNUxxd5TiZL87_v6JOx61umsUz
## Intranet
https://profile.intra.42.fr/
il faut s'inscrire aux projets mais **aussi à l'examen** (2 fois agenda examen et projet examen)

## Turn in System
après le rendu il faut choisir une plage horaire pour la défense (perds 1 point)
pour évaluer un projet : accueil->manage slots et choisir une plage horaire pour la défense (gagne 1 point)
un rush le weekend se termine toujours à 23h42 le dimanche

## Turn In System
setup du système de rendu à suivre
https://www.youtube.com/watch?v=1zN-m25vcmA&list=PLVQYiy6xNUxxd5TiZL87_v6JOx61umsUz&index=4

pour travailler depuis la maison il faut supprimer la clé ssh pour en créer une nouvelle et refaire le setup
**et ajouter la clé dans l'agent**
```
ssh-agent -s
ssh-add ~/.ssh/id_rsa
```
https://stackoverflow.com/a/30806058

## Pédagogique
**Le Guide du Voyageur Galactique** par Douglas Adams
- formaliser avec un papier, notes
- communiquer avec les autres, expliquer, critiquer, interroger
- tester, tester et tester (des petits tests et chercher des failes)
- regarder en arrière (introspection, progression par l'échec)
  - comparer avec les autres
  - se remettre en question

#### vogsphere
serveur de rendu qui utilise git

- d'abord clone le repo
```
git clone vogsphere@vogsphere.42.fr... j00
git clone vgs:pisc-0-001... j00
```
- et ensuite pour le premier `push`
```
git push origin master
```

pour creer les dossier exXX avec la commande
```
mkdir -p ex{00..08}
```

authentification sur le serveur se fait avec un ticket kerberos
normalement est obtenu après l'authentification mais peut expiré
pour afficher la liste des tickets et pour obtenir un nouveau ticket
```
klist
kinit login
```

## vim
https://devhints.io/vim
```
vim file
```
#### les modes
- `i` : mode insertion pour écrire
- `escape` : mode interactif pour se déplacer, copier, coller, supprimer, ...
- `:` : mode commande pour utiliser des commandes, sauvegarder, quiter, ...

#### commandes
`:e file`: pour ouvrir un nouveau fichier
`:vs`: pour séparer en deux
`:crt+w`: pour se déplacer entre les buffers avec les flêches
`:Stdheader`: pour générer le header


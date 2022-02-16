# born2beroot
## liste des commandes
- `crontab -e` : editer cron
- `service --status-all` : liste de tous les services
- `uname -a` : affiche les informations sur le système d'exploitation
- `service ufw status` : vérifier si ufw est activé
- `service ssh status` : vérifier si ssh est activé
- `getent group sudo` : les membres du groupe sudo
- `chage -l bel-mous` : information sur le mot de passe de l'utilisateur spécifié
- `adduser test` : ajoute un utilisateur test
- `addgroup evaluating` : ajoute un groupe evaluating
- `usermod -a -G group user` || `sudo adduser user group` : ajoute user à group
- `lsblk` : afficher le partitionnement
- `nano /etc/hostname` : modification du hostname
- `reboot` : reboot de la machine
- `ufw status` : les ports ouverts
- `ufw allow 8080` : ouvre le port 8080
- `ufw delete allow 8080` : ferme le port 8080
- `ssh bel-mous@127.0.0.1 -p 4242` : pour se connecter via ssh
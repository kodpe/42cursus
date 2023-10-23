#### mariadb help commands
```
docker exec -it mariadb sh
mysql -u sloquet -p inception_db
SHOW TABLES;
SELECT * FROM wp_users;
quit
```

#### VM
```
VM password root : p
VM constant root : sudo -s
VM install ps : apt install procps
```

##### HELP
```
error release not valid yet
solution: sudo hwclock --hctosys
https://askubuntu.com/questions/1096930/sudo-apt-update-error-release-file-is-not-yet-valid
```
```
php-fpm81
https://pkgs.alpinelinux.org/package/edge/community/aarch64/php81-fpm
https://www.cyberciti.biz/faq/how-to-reload-restart-php7-0-fpm-service-linux-unix/
```
```
mariaDB
https://fromdual.com/mysql-configuration-file-sample
https://www.val-r.fr/geek/os/linux/installer-un-serveur-linux-sous-debian/installation-et-configuration-du-serveur-mysql-mariadb/
https://zetcode.com/mysql/firststeps/#:~:text=We%20check%20the%20status%20with%20the%20systemctl%20status%20mysql%20command.&text=We%20use%20the%20mysqladmin%20tool,a%20password%20for%20the%20user
```

```
cat /etc/hosts
sudo lsof -i :80
sudo lsof -i :443
sudo nginx -t       # check .conf
xdg-open <url>
```

```
docker system prune -af
docker stop 07 2e b8

docker images
docker ps -a
docker logs nginx
docker volume ls
docker-compose ps   # work only with docker-compose.yml

docker build -t img .
docker run -d -p 8080:80 --name img conteneur

docker exec -it conteneur service nginx status
docker exec -it conteneur /bin/sh
```

```
curl -Ik http://sloquet.42.fr
```

#### old help
```

docker build -t nameImage .
docker images -a
docker ps -a

docker run ID -d detach -p port
docker run --name <nom> <image> <cmd>
on est oblige de mettre une commande et c est la commande pid1 elle va
determiner quand le conteneur s arrete

docker stop ID
docker rm ID
docker system prune
docker search name # pour chercher une img sur docker hub
docker pull name # pour obtenir une img sur docker hub
docker push # pour envoyer une img sur docker hub

.dockerignore # combine avec ADD


------------------
!!! TODO IMPORTANT ouvrir le port -p 8080


sudo docker system prune -af

docker ps
pour voir les conteneurs en marche

docker ps -a
pour voir aussi ceux qui sont arretes

docker run
lancer les conteneurs
exemple :
docker run --name <nom> <image> <cmd>
on est oblige de mettre une commande et c est la commande pid1 elle va
determiner quand le conteneur s arrete

docker exec
permet d executer une commande dans un conteneur deja en marche
en general pour ouvrir un bash
exemple
docker exec -it <conteneur name> bash
it pour interactif

docker stop
arreter le container en route mais on peut le relancer avec
docker start

docker build
pour construire une image a partir du dockerfile

service
on peut utiliser service dans les containers (bash interactif)
pour faciliter les tests

service --status-all
pour voir les services actifs dans le container
service <app> start/stop

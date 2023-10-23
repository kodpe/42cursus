#!/bin/sh

if [ ! -e "/var/lib/mysql/installed" ]; then

    #echo -e "\nCP 0 openrc fix"
    mkdir -p /run/openrc
    touch /run/openrc/softlevel
    rc-update add mariadb default
    rc-status

    #echo -e "\nCP 1 init"
    /usr/bin/mysql_install_db --user=root --basedir=/usr --datadir=/var/lib/mysql

    #echo -e "\nCP 2 active service"
    rc-service mariadb restart
    sleep 3

    #echo -e "\nCP 3 setup"
    mysql --user=root -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;"
    mysql --user=root -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'localhost' IDENTIFIED BY '${DB_PASSWORD}';"
    mysql --user=root -e "GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
    mysql --user=root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
    mysql --user=root -p$DB_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"

    #echo -e "\nCP 4 installed"
    mysqladmin -u root -p$DB_ROOT_PASSWORD shutdown
	touch /var/lib/mysql/installed
else
    echo "database already installed"
fi

/usr/bin/mysqld --user=root --datadir=/var/lib/mysql

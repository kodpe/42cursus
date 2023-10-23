#!/bin/sh

if [ ! -e "/var/www/html/installed" ]; then

	sleep 15
	date
    #echo -e "\nCP 0 install wp cli"
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv -f wp-cli.phar /usr/local/bin/wp

    #echo -e "\nCP 1 download wp"
	/usr/local/bin/wp --info
	/usr/local/bin/wp core download --allow-root --path="/var/www/html"

    #echo -e "\nCP 2 configure wp"
	rm -f /var/www/html/wp-config.php
	cp ./wp-config.php /var/www/html/wp-config.php
	sed -i 's#go to <a href="%s">your dashboard</a> to delete#delete#g' /var/www/html/wp-admin/includes/upgrade.php

	/usr/local/bin/wp core install \
				--allow-root \
				--path="/var/www/html" \
				--url="sloquet.42.fr" \
				--title="InceptionHello" \
				--admin_user="$WP_ADMIN_LOGIN" \
				--admin_password="$WP_ADMIN_PASSWORD" \
				--admin_email="$WP_ADMIN_EMAIL" \
				--skip-email

    #echo -e "\nCP 3 add user"
	/usr/local/bin/wp user create \
				--allow-root \
				--path="/var/www/html" \
				"$WP_USER_LOGIN" \
				"$WP_USER_EMAIL" \
				--user_pass="$WP_USER_PASSWORD" \
				--role=author

    #echo -e "\nCP 4 wp installed"
	touch /var/www/html/installed
else
	echo "wp already installed"
fi

exec php-fpm81 -F -R --nodaemonize

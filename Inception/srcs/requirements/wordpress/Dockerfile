FROM alpine:3.17

RUN apk update && apk upgrade && apk add --no-cache \
	curl \
   	php81 \
    php81-common \
	php81-mysqlnd \
	php81-mysqli \
	php81-fpm \
    php81-gd \
    php81-ctype \
    php81-curl \
    php81-iconv \
    php81-mbstring \
    php81-openssl \
    php81-phar \
    php81-session

RUN		ln -s /etc/init.d/php-fpm81 /etc/init.d/php-fpm \
    && rm -f /etc/php81/php-fpm.d/www.conf \
    && mkdir -p /var/www/html \
    && adduser -u 98 -D -S -G www-data www-data \
    && chmod 755 -R /var/www/html \
    && chown -R www-data:www-data /var/www/html

# www-data is the default user sc

COPY	conf/default.conf /etc/php81/php-fpm.d/www.conf

COPY	tools/setup-wordpress.sh conf/wp-config.php ./

CMD     ["sh", "setup-wordpress.sh"]

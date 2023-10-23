FROM alpine:3.17

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb \
    mariadb-client \
    openrc \
    && mkdir -p /var/run/mysqld \
    && mkdir -p /var/lib/mysql \
    && chown -R mysql /var/lib/mysql \
    && chmod 755 /var/lib/mysql

COPY conf/my.cnf /etc/mysql/my.cnf

COPY tools/setup-mariadb.sh ./

CMD ["sh", "setup-mariadb.sh"]


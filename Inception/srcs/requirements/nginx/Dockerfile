FROM alpine:3.17

RUN apk update && apk upgrade \
	&& apk add --no-cache nginx \
	&& mkdir -p /var/www/html \
	&& apk add openssl \
	&& mkdir -p /etc/nginx/ssl \
	&& openssl req \
		-newkey rsa:4096 \
		-x509 \
		-sha256 \
		-days 365 \
		-nodes \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=sloquet/CN=sloquet.42.fr" \
		-keyout /etc/nginx/ssl/inception.key \
		-out /etc/nginx/ssl/inception.cert

COPY conf/default.conf /etc/nginx/http.d/default.conf

EXPOSE	443

CMD		["nginx", "-g", "daemon off;"]

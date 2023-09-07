FROM debian:bullseye

RUN 	apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install \
		nginx \
		openssl \
		vim

COPY    conf/nginx.conf /etc/nginx/sites-available/default

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=localhost" \
		-out /etc/ssl/certs/sanghan.42.fr.crt \
		-keyout /etc/ssl/private/sanghan.42.fr.key

ENTRYPOINT     ["nginx", "-g", "daemon off;"]

EXPOSE 443

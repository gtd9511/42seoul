FROM	debian:bullseye

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install php7.4-fpm \
		vim \
		wget \
		curl \
		tar \
		mariadb-client \
		php-cli \
		php-mysql \
		sudo

# RUN		wget https://wordpress.org/latest.tar.gz
# RUN		tar -xvzf latest.tar.gz
# RUN		mkdir -p /var/www/html/wordpress
# RUN		mv wordpress/ var/www/html/

COPY	./tools/wordpress_setup.sh /tmp/wordpress_setup.sh
COPY	./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
		chmod +x wp-cli.phar && \
		mv wp-cli.phar /usr/local/bin/wp

# RUN mkdir -p /var/www/html && \
#     chown -R  www-data:www-data /var/www/html

RUN		mkdir -p /var/www/html/wordpress && \
		chown -R www-data:www-data /var/www/html/wordpress

RUN		mkdir -p /run/php && \
		chmod +x /run/php

WORKDIR	/var/www/html/wordpress

EXPOSE	9000

ENTRYPOINT ["sh", "/tmp/wordpress_setup.sh"]


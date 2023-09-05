FROM	debian:buster

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install php7.3-fpm \
		vim \
		wget \
		tar \
		mariadb-client \
		php-cli \
		php-mysql \
		php-mbstring \
		sudo

RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvzf latest.tar.gz
RUN		mkdir -p /var/www/html/wordpress
RUN		mv wordpress/ var/www/html/

COPY	./tools/wordpress_setup.sh /tmp/wordpress_setup.sh
COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

WORKDIR	/var/www/html/wordpress
RUN		mkdir -p /run/php

# RUN		chown -R www-data:www-data /var/www/html/wordpress

EXPOSE	9000

ENTRYPOINT ["sh", "/tmp/wordpress_setup.sh"]
# CMD		service php7.3-fpm start && tail -f /dev/null
# tall-f 지우기

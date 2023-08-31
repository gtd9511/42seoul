FROM	debian:buster

# RUN		apt-get update -y && \
# 		apt-get upgrade -y && \
# 		apt-get -y install \
# 		mariadb-server \
# 		mariadb-client

RUN		apt-get update -y
RUN		apt-get upgrade -y
RUN		apt-get install mariadb-server -y
RUN		apt-get install mariadb-client -y

COPY	./tools/mariadb_setup.sh /tmp/mariadb_setup.sh
COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

ENTRYPOINT ["sh", "/tmp/mariadb_setup.sh"]

EXPOSE 3306

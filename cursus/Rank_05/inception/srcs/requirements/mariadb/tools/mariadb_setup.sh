# #!/bin/sh

set -e

MYSQL_SETUP_FILE=/var/lib/mysql/.setup

service mariadb start;

if [ ! -e $MYSQL_SETUP_FILE ]; then # 처음에만 실행

	# mysql -e : mysql 에서 명령을 실행

	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
	mysql -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
	# 변경사항을 적용
	mysql -u root -e "FLUSH PRIVILEGES";
	# root 계정의 비밀번호를 변경
	mysql -u root -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

	mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
	mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

	touch $MYSQL_SETUP_FILE
fi

exec mysqld --user=root

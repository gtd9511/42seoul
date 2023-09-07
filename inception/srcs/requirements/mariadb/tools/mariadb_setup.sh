# # # #!/bin/sh

# set -e

# MYSQL_SETUP_FILE=/var/lib/mysql/.setup

# service mariadb start;

# if [ ! -e $MYSQL_SETUP_FILE ]; then # 처음에만 실행되도록 하기 위해서

# 	# mysql -e : mysql 에서 명령을 실행하라는 의미

# 	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
# 	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
# 	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
# 	# 변경사항을 적용하라는 의미
# 	mysql -e "FLUSH PRIVILEGES";
# 	# root 계정의 비밀번호를 변경한다.
# 	mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

# 	mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
# 	mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

# 	touch $MYSQL_SETUP_FILE
# fi

# exec mysqld --console

# #!/bin/sh

set -e

MYSQL_SETUP_FILE=/var/lib/mysql/.setup

service mariadb start;
# service mysql start;

if [ ! -e $MYSQL_SETUP_FILE ]; then # 처음에만 실행되도록 하기 위해서

	# mysql -e : mysql 에서 명령을 실행하라는 의미

	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
	mysql -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
	# 변경사항을 적용하라는 의미
	mysql -u root -e "FLUSH PRIVILEGES";
	# root 계정의 비밀번호를 변경한다.
	mysql -u root -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

	mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
	mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

	touch $MYSQL_SETUP_FILE
fi

# exec mysqld --console
exec mysqld --user=root


# #!/bin/bash

# if [ ! -d /var/lib/mysql/${WORDPRESS_DB_NAME} ]; then

#     mariadb-install-db

#     service mariadb start

#     mysql -u root -e "CREATE DATABASE $WORDPRESS_DB_NAME;"
#     mysql -u root -e "CREATE user $WORDPRESS_DB_USER@'%' identified by '$WORDPRESS_DB_PASSWORD';"
#     mysql -u root -e "GRANT ALL PRIVILEGES ON $WORDPRESS_DB_NAME.* TO $WORDPRESS_DB_USER@'%';"
#     mysql -u root -e "FLUSH PRIVILEGES;"

#     service mariadb stop

# else
#     echo "-- MariaDB already setted--"
# fi

# mysqld --user=root


# # if [ ! -d /var/lib/mysql/${MYSQL_NAME} ]; then
# #     # mysql_install_db
# #     service mariadb start
# #     mariadb <<- EOF
# #     CREATE DATABASE IF NOT EXISTS wordpress;
# #     CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
# #     GRANT ALL PRIVILEGES ON wordpress.* TO '${MYSQL_USER}'@'%';
# #     FLUSH PRIVILEGES;
# #     EOF
# # else
# #     echo "MySQL db already exists."
# # fi
# #     service mariadb stop


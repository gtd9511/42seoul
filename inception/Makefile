# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 19:38:51 by sanghan           #+#    #+#              #
#    Updated: 2023/09/11 19:34:06 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

VOLUME_PATH	:=	/home/sanghan/data
HOST_LINK	:=	"127.0.0.1	sanghan.42.fr" > /etc/hosts


$(NAME) :
	@sudo mkdir -p $(VOLUME_PATH)/mariadb/
	@sudo mkdir -p $(VOLUME_PATH)/wordpress/
	@sudo echo $(HOST_LINK)
	@sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

all: $(NAME)

up:
	@sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

down:
	@sudo docker-compose -f ./srcs/docker-compose.yml down

clean:
	@sudo docker-compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@sudo docker system prune -a -f

fclean: clean
	@sudo rm -rf $(VOLUME_PATH)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re down

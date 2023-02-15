# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 10:24:10 by sanghan           #+#    #+#              #
#    Updated: 2022/01/27 14:19:59 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./main.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op


$(NAME): ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all: $(NAME)
	
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 08:41:49 by sanghan           #+#    #+#              #
#    Updated: 2022/01/26 21:12:34 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INCS = includes
CC		= gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCS}

$(NAME): ${OBJS}
	ar crvs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re .c.o

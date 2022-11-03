# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 13:42:19 by sanghan           #+#    #+#              #
#    Updated: 2022/09/01 20:17:53 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c ft_printput.c ft_itoa.c ft_puthex.c
OBJS = ${SRCS:.c=.o}

 %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean fclean re

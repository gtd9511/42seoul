# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 01:06:38 by sanghan           #+#    #+#              #
#    Updated: 2022/11/16 15:57:29 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIB_PATH = ./libft
SRCS_PATH = ./sources
OBJS_PATH = ./objects
INCLUDES = ./includes

SRCS = push_swap.c get_input.c make_array.c stack.c stack_utils.c \
		cmd_sp.c cmd_r.c set_point.c sort.c sort_utils.c
OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIB_PATH) all
	$(CC) $(CFLAGS) -L$(LIB_PATH) -lft $^ -o $@

all: $(NAME)

clean:
	make -C $(LIB_PATH) clean
	$(RM) $(OBJS_PATH)

fclean: clean
	make -C $(LIB_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

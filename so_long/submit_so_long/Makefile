# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 00:35:25 by sanghan           #+#    #+#              #
#    Updated: 2022/11/03 17:34:34 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIB_PATH = ./libft
MLX_PATH = ./mlx
SRCS_PATH = ./sources
OBJS_PATH = ./objects
INCLUDES = ./includes

SRCS = so_long.c window.c map.c play.c handler.c error.c
OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIB_PATH) all
	make -C $(MLX_PATH) all
	$(CC) $(CFLAGS) -L$(LIB_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit $^ -o $@

all: $(NAME)

clean:
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS_PATH)

fclean: clean
	make -C $(LIB_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

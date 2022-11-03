# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 11:15:12 by sanghan           #+#    #+#              #
#    Updated: 2022/10/07 16:25:50 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIB_PATH = libft
INCLUDES = -I includes
OBJS_PATH = objects

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

ifeq ($(BONUS), true)
	SRCS_PATH = bonus
	OBJS_SERVER_NAME = $(SRCS_SERVER_BONUS:.c=.o)
	OBJS_SERVER = $(addprefix $(OBJS_PATH)/, $(OBJS_SERVER_NAME))
	OBJS_CLIENT_NAME = $(SRCS_CLIENT_BONUS:.c=.o)
	OBJS_CLIENT = $(addprefix $(OBJS_PATH)/, $(OBJS_CLIENT_NAME))
else
	SRCS_PATH = sources
	OBJS_SERVER_NAME = $(SRCS_SERVER:.c=.o)
	OBJS_SERVER = $(addprefix $(OBJS_PATH)/, $(OBJS_SERVER_NAME))
	OBJS_CLIENT_NAME = $(SRCS_CLIENT:.c=.o)
	OBJS_CLIENT = $(addprefix $(OBJS_PATH)/, $(OBJS_CLIENT_NAME))
endif

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME_SERVER): $(OBJS_SERVER) $(NAME_CLIENT)
	$(CC) $(CFLAGS) -L./$(LIB_PATH) -lft -o $(NAME_SERVER) $(OBJS_SERVER)
$(NAME_CLIENT): $(OBJS_CLIENT)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) -L./$(LIB_PATH) -lft -o $(NAME_CLIENT) $(OBJS_CLIENT)

all: $(NAME_SERVER)

bonus:
	make BONUS=true all

clean:
	make -C $(LIB_PATH) fclean
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re

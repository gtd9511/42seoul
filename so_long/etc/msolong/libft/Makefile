# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:40:54 by sanghan           #+#    #+#              #
#    Updated: 2022/05/20 09:34:18 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = ./libft.h

FILES = ft_split \
		ft_strlcpy \
		ft_strlen \
		ft_strlcat \
		ft_strncmp \
		ft_strjoin \
		ft_strdup \
		ft_itoa \
		
		
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o : %.c
	$(CC) $(CLFAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $?

all: $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

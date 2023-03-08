# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:07:32 by sanghan           #+#    #+#              #
#    Updated: 2023/03/08 16:07:33 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pho

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -rf

SRCS_PATH = ./sources
OBJS_PATH = ./objects
INCLUDES = ./includes

SRCS = main.cpp
OBJS_NAME = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	mkdir -p $(OBJS_PATH)
	$(CC) $(CPPFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

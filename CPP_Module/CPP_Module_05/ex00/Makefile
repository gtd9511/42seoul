# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:46:34 by sanghan           #+#    #+#              #
#    Updated: 2023/03/23 19:46:48 by sanghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address
RM = rm -rf

SRCS_PATH = ./sources
OBJS_PATH = ./objects
INCLUDES = ./includes

SRCS =
OBJS_NAME = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	mkdir -p $(OBJS_PATH)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# #**************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2022/12/15 19:17:06 by sanghan           #+#    #+#              #
# #    Updated: 2023/01/09 14:45:05 by sanghan          ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# NAME = minishell

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g
# RM = rm -rf

# LIB_PATH = ./libft
# SRCS_PATH = ./sources
# OBJS_PATH = ./objects
# INCLUDES = ./includes
# # srcs directory
# LEXER_DIR = lexer
# PARSER_DIR = parser
# BUILTIN_DIR = builtin
# EXEC_DIR = execute
# ENV_DIR = env
# UTILS_DIR = utils

# LEXER_SRCS = lexer.c labeling.c check_odd_quote.c lexer_error.c
# PARSER_SRCS = check.c delete_blank.c merge_string.c parser_token.c remove_quote.c replace_env.c sort_redirection.c
# BUILTIN_SRCS = ft_env.c ft_export.c ft_unset.c ft_pwd.c ft_echo.c ft_exit.c ft_cd.c
# EXEC_SRCS = exec_builtin.c exec_cmd.c redir.c exec_pipe.c
# ENV_SRCS = init_env.c utils.c
# UTILS_SRCS = signal.c
# LDFLAGS = -L/opt/homebrew/opt/readline/lib
# CPPFLAGS = -I/opt/homebrew/opt/readline/include
# #LDFLAGS = -L/goinfre/sanghan/.brew/opt/readline/lib
# #CPPFLAGS = -I/goinfre/sanghan/.brew/opt/readline/include
# READ_LIB = -lreadline

# SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
# 	$(addprefix $(SRCS_DIR)/$(LEXER_DIR)/, $(LEXER_SRCS)) \
# 	$(addprefix $(SRCS_DIR)/$(PARSER_DIR)/, $(PARSER_SRCS)) \
# 	$(addprefix $(SRCS_DIR)/$(BUILTIN_DIR)/, $(BUILTIN_SRCS)) \
# 	$(addprefix $(SRCS_DIR)/$(EXEC_DIR)/, $(EXEC_SRCS)) \
# 	$(addprefix $(SRCS_DIR)/$(ENV_DIR)/, $(ENV_SRCS)) \
# 	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS))
# OBJS_NAME = $(SRCS:.c=.o)
# OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

# $(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
# 	mkdir -p $(OBJS_PATH)
# 	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# $(NAME) : $(OBJS)
# 	make -C $(LIB_PATH) all
# 	$(CC) $(CFLAGS) -I $(INCLUDES) $(LDFLAGS) $(CPPFLAGS) $(READ_LIB) -L$(LIB_PATH) -lft $^ -o $@

# all: $(NAME)

# clean:
# 	make -C $(LIB_PATH) clean
# 	$(RM) $(OBJS_PATH)

# fclean: clean
# 	make -C $(LIB_PATH) fclean
# 	$(RM) $(NAME)

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# .PHONY: all bonus clean fclean re#


NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_DIR = includes
LIBS_DIR = libft
SRCS_DIR = sources

# srcs directory
LIB_PATH = ./libft
LEXER_DIR = lexer
PARSER_DIR = parser
BUILTIN_DIR = builtin
EXEC_DIR = execute
ENV_DIR = env
UTILS_DIR = utils

LEXER_SRCS = lexer.c labeling.c check_odd_quote.c lexer_error.c
PARSER_SRCS = check.c delete_blank.c merge_string.c parser_token.c remove_quote.c replace_env.c sort_redirection.c
BUILTIN_SRCS = ft_env.c ft_export.c ft_unset.c ft_cd.c ft_echo.c ft_exit.c ft_pwd.c
EXEC_SRCS = exec_builtin.c exec_cmd.c redir.c exec_pipe.c
ENV_SRCS = init_env.c utils_env.c
UTILS_SRCS = signal.c

# readline
LDFLAGS = -L/opt/homebrew/opt/readline/lib
CPPFLAGS = -I/opt/homebrew/opt/readline/include
# LDFLAGS = -L/goinfre/$(USER)/.brew/opt/readline/lib
# CPPFLAGS = -I/goinfre/$(USER)/.brew/opt/readline/include
READ_LIB = -lreadline

#LIBFT_DIR = libft/libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(LEXER_DIR)/, $(LEXER_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(PARSER_DIR)/, $(PARSER_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(BUILTIN_DIR)/, $(BUILTIN_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(EXEC_DIR)/, $(EXEC_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(ENV_DIR)/, $(ENV_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_PATH) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) $(READ_LIB) $(LDFLAGS) $(CPPFLAGS) -L $(LIB_PATH) -lft -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIB_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY = all clean fclean re

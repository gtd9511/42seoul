/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:51:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/05 20:00:04 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define MAXSIZE		1024

# define FALSE			0
# define TRUE			1

# define ERROR			-1
# define SUCCESS 		1

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define COLOR_BR_BLUE	"\033[34;1m"
# define COLOR_WHITE	"\033[37m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_CYAN		"\033[36m"
# define END_COLOR		"\033[0m"

# define NORMAL_STRING 0
# define DOUBLE_QUOTE 1
# define SINGLE_QUOTE 2
# define BLANK 3
# define PIPE 4
# define REDIR_IN 5
# define REDIR_HEREDOC 6
# define REDIR_OUT 7
# define REDIR_DOUBLE_OUT 8
# define AFTER_HEREDOC 9
# define AFTER_HEREDOC_DQ 10
# define AFTER_HEREDOC_SQ 11
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_parser_token
{
	t_list	*cmd;
	t_list	*in;
	t_list	*out;
}	t_parser_token;

typedef struct s_exec_token
{
	t_parser_token	*parser_token;
	char			**cmd;
}	t_exec_token;

t_env	*make_env_node(char *key, char *value);
void	env_list_add_node(t_env **list, t_env *node);
int	is_key_in_env_list(char *key, t_env *env_list);

#endif

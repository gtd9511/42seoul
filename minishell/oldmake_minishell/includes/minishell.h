/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:51:04 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/09 16:26:23 by sanghan          ###   ########.fr       */
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
//# include <term.h>
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
int		is_key_in_env_list(char *key, t_env *env_list);
void	free_env_list(t_env *env_list);
t_env	*init_env_list(char **envp);


void				setting_signal();
void				set_echoctl_off(void); // ctrl+c not print

void				lexer(char *str, t_list **lexer_token);
void				labeling(t_list *lexer_token);
void				labeling_after_heredoc(t_list *lexer_token);
int					check_odd_quote(t_list *lexer_token); // 0 : 짝수 따옴표, 1 : 홀수 따옴표
void				replace_env(t_list *l_tok, t_env *envlst);
void				remove_quote(t_list **lexer_token);
void				merge_string(t_list **lexer_token);
void				delete_node(char *key, t_env **env_list);
int					check_redirection(t_list *lexer_token);
int					check_double_pipe(t_list *lexer_token);
int					parser_token_size(t_list *lexer_token);

void				clear_and_exit(t_list **lexer_token);
void				make_parser_token(t_list **lexer_token, t_parser_token *parser_token);
void				delete_blank(t_list **lexer_token);
void				sort_redirection(t_parser_token *parser_token, int len);
void				exec_cmd(t_exec_token *token, t_env *env_list, int len);
void	free_temp_clear_and_exit(t_list **lexer_token, char *temp);
t_parser_token		*init_parser_token(int size);
char	*get_env_value(t_env *env_list, char *key);
void	print_env_list(t_env *env_list);
int	ft_cd(t_parser_token *parser_token);
int	ft_echo(t_exec_token *token);
int	ft_env(char **cmd, t_env *env_list);
int	ft_exit(t_parser_token *parser_token);
int	ft_export(char **cmd, t_env *env_list);
int	ft_pwd(char **cmd);
int	ft_unset(char **cmd, t_env *env_list);
void	make_pipe(t_exec_token token, t_env *env_list);
void	set_redir(t_parser_token *parser_token, t_env *env_list);
int	is_builtin(t_exec_token *token);
void	exec_builtin(t_exec_token *token, t_env *env_list);
void	run_execve_cmd(char **cmd_list, t_env *env_list);
char	**convert_env_list_to_str_list(t_env *env_list);
void	free_split(char **str);
char	*get_path(char *cmd, char **env);
void	error_exit(char *str, int status);
void	join_key_and_value(char **env_str, t_env *env_list);
void	get_infile(char *limiter, t_env *env_list);
void	set_redir_in(char *redir_sign, char *filename);
void	set_redir_out(char *redir_sign, char *filename);
char	*replace_env_heredoc(char *str, t_env *env_list);
char	*join_env(char *before, char *value, char *after);
void	child_process(int *fd, t_exec_token token, t_env *env_list);
void	parent_process(int *fd);
void	sig_handler(int signal);
void	delete_node(char *key, t_env **env_list);




#endif
